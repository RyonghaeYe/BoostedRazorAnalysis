import os, sys, glob, time, logging, multiprocessing, subprocess, shlex, ROOT
from optparse import OptionParser

# ---------------------- Cmd Line  -----------------------

# Read options from command line
usage = "Usage: python %prog filelists [options]"
parser = OptionParser(usage=usage)
parser.add_option("--run",     dest="run",     action="store_true", default=False,   help="Without this option, script only prints cmds it would otherwise excecute")
parser.add_option("--full",    dest="full",    action="store_true", default=False,   help="Run on all datasets found in filelists directory")
parser.add_option("--test",    dest="test",    action="store_true", default=False,   help="Run only on some test files (jetht, ttbar, qcd, T5ttcc)")
parser.add_option("--batch",   dest="batch",   action="store_true", default=False,   help="Send the jobs to batch")
parser.add_option("--queue",   dest="QUEUE",   type="string",       default="1nh",   help="Specify which batch queue to use (Default=1nh)")
parser.add_option("--quick",   dest="NQUICK",  type="int",          default=0,       help="Run only on a subset of events (1/NQUICK)")
parser.add_option("--nevt",    dest="NEVT",    type="int",          default=-1,      help="Tells how many event to run as a maximum in a single job (Default=-1 all)")
parser.add_option("--nfile",   dest="NFILE",   type="int",          default=-1,      help="Tells how many input files to run in a single job (Default=-1 all)")
parser.add_option("--sleep",   dest="SLEEP",   type="int",          default=3,       help="Wait for this number of seconds between submitting each batch job (Default 3s)")
parser.add_option("--useprev", dest="useprev", action="store_true", default=False,   help="Use previously created temporary filelists")
parser.add_option("--nproc",   dest="NPROC",   type="int",          default=3,       help="Tells how many parallel interactive jobs to start (Default=3)")
parser.add_option("--outdir",  dest="OUTDIR",  type="string",       default="",      help="Output directory (Default: results/run_[DATE])")
parser.add_option("--skimout", dest="SKIMOUT", type="string",       default="",      help="Output directory for skimming")
parser.add_option("--skim",    dest="skim",    action="store_true", default=False,   help="Skim output to --skimout directory (change in script)")
parser.add_option("--mirror",  dest="mirror",  action="store_true", default=False,   help="Also copy skim output to EOS")
parser.add_option("--plot",    dest="plot",    action="store_true", default=False,   help="Make plots after running using Plotter (Janos)")
parser.add_option("--replot",  dest="replot",  action="store_true", default=False,   help="Remake latest set of plots using Plotter (Janos)")
(opt,args) = parser.parse_args()

# ----------------------  Settings -----------------------
# Some further (usually) fixed settings, should edit them in this file

# Output directories/files
DATE = time.strftime("%Y_%m_%d_%Hh%Mm%S", time.localtime())
if opt.OUTDIR == "" and not opt.skim:
    opt.OUTDIR = "results/run_"+DATE # log files, backup files, output files for non-skims

if opt.skim:
    if opt.OUTDIR == "":
        opt.OUTDIR = "results/skim_"+DATE # log files, backup files, output files for non-skims
    # Mirror also here
    if opt.SKIMOUT == "":
        print "ERROR: Give a suitable --skimout argument, eg. --skimout ntuple/grid18/Skim_Oct31_2Jet_1JetAK8"
        sys.exit()
    if opt.NFILE == -1 and opt.NEVT == -1:
        print "ERROR: Give a suitable --nfile or --nevt argument, otherwise output might become too large!"
        sys.exit()
    if opt.NQUICK>1:
        if opt.mirror:
            print "ERROR: Please, don't mirror stuff to EOS, when testing!"
            sys.exit()
    else:
        if opt.mirror:
            # --mirror copies here
            EOS_JANOS  = "srm://srm-eoscms.cern.ch/eos/cms/store/caf/user/jkarancs/B2GTTreeNtuple/"
        else:
            # If not, then makes a script for Viktor
            EOS_VIKTOR = "srm://srm-eoscms.cern.ch/eos/cms/store/caf/user/veszpv/B2GTTreeNtuple/"
            COPYSCRIPT = opt.SKIMOUT.replace(opt.SKIMOUT.split("/")[-1],"")+"mirror_to_Viktors_EOS_"+opt.SKIMOUT.split("/")[-1]+".sh"
            print "Warning: Don't you want to mirror to EOS? Add: --mirror option!"
            print "         If not, ignore this message!"
            print "         Creating a copy script for Viktor: "+COPYSCRIPT
if opt.batch and opt.NEVT == -1 and not opt.useprev:
    print "ERROR: Give a suitable --nevt argument, otherwise some jobs will run too long on batch!"
    print "       Recommended option for 1nh queue: --nevt=2000000 (~30min/job, ~1000 evt/s is usual)"
    print "       Or use --useprev option to run on previously created temporary filelists"
    sys.exit()
if opt.plot:
    #PLOTTER_IN automatic
    PLOTTER_OUT = "results/Plotter_test.root" if opt.test else "results/Plotter_out_"+DATE+".root"
if opt.replot:
    if opt.OUTDIR == "":
        # Find last working directory automatically and find output files there
        opt.OUTDIR = max( glob.glob("results/run_*"), key=os.path.getmtime )
        PLOTTER_IN = max(glob.glob("results/Plotter_out_*.root"), key=os.path.getmtime).replace("_replot","")
        PLOTTER_OUT = PLOTTER_IN.replace(".root","_replot.root")
        PLOTTER_INT = [PLOTTER_IN]
    else:
        PLOTTER_IN = glob.glob(opt.OUTDIR+"/*.root")
        PLOTTER_OUT = opt.OUTDIR.replace("run_", "Plotter_out_")+"_replot.root"

# Working directory, during running we cd here and back
if opt.test:
    EXEC_PATH = os.getcwd()
elif opt.replot:
    EXEC_PATH = opt.OUTDIR+"/backup_replot"
elif not opt.test:
    EXEC_PATH = opt.OUTDIR+"/backup"

# Print some options for logging
if not opt.run:
    print "--run option not specified, doing a dry run (only printing out commands)"

if opt.full:
    print "Running with option: --full"
elif opt.skim:
    print "Running with option: --skim"
elif opt.replot:
    print "Running with option: --replot"
    opt.plot = 0 # for safety
elif opt.test:
    print "Running with option: --test (few files)"

if opt.plot:
    print "Running with option: --plot (will produce plots with Plotter)"

if opt.NQUICK>1:
    print "Running with option: --quick "+str(opt.NQUICK)+" (1/"+str(opt.NQUICK)+" statistics)"

# Some automatic filelists
if (opt.full):
    input_filelists  = glob.glob("filelists/data/*.txt")
    input_filelists += glob.glob("filelists/backgrounds/*.txt")
    input_filelists += glob.glob("filelists/signals/*.txt")
elif opt.test:
    input_filelists  = glob.glob("filelists/data/JetHT*.txt")
    input_filelists += glob.glob("filelists/backgrounds/QCD_HT*.txt")
    input_filelists += glob.glob("filelists/backgrounds/TT_powheg-pythia8_ext4*.txt")
    input_filelists += glob.glob("filelists/signals/FastSim_SMS-T5ttcc*.txt")
elif not opt.replot and len(args) < 1:
    print "Always tell me what filelists to run over (except when using --full or --test options)!"
    print "For more help, run as python %s -h" % (sys.argv[0])
    sys.exit()
else:
    input_filelists = args

# ----------------- Analyzer Arguments -------------------
# Analyzer (see below in functions):
# Each element supplies 3 arguments for each Analyzer job:
# [output filename, input file list, output log]
# For skimming/full running, all datasets are used
# for testing a selected few

if opt.useprev:
    print "Reusing previously created temporary filelists for split jobs (eg. --batch) in filelists_tmp/:"
elif (opt.NFILE != -1 or opt.NEVT != -1):
    print "Start creating new temporary filelists for split jobs (eg. batch) in filelists_tmp/:"
    for tmp_txtfile in glob.glob('filelists_tmp/*/*.txt'): os.remove(tmp_txtfile)

ana_arguments = []
# Loop over all filelists
for filelist in input_filelists:
    # Will put all files into the OUTDIR and its subdirectories
    log_file = opt.OUTDIR+"/log/"+filelist.split("/")[-1].replace("txt", "log")
    if opt.skim:
        # Except for skim, where we send the large output files to a different directory
        # keeping subdirectory structure (suitable for a future input )
        output_file = opt.SKIMOUT+"/"+filelist.split("/")[-1].replace(".txt","/Skim.root")
    else:
        output_file = opt.OUTDIR +"/"+filelist.split("/")[-1].replace("txt", "root")
    # Now let's make the argument list for the Analyzer jobs
    options = []
    if opt.NQUICK>1: options.append("quickTest="+str(opt.NQUICK))
    if opt.skim and not opt.plot: options.append("noPlots=1")
    # Temporary filelists
    if opt.useprev:
        # Use previously created lists
        prev_lists = glob.glob(filelist.replace("filelists","filelists_tmp").replace(".txt","_*.txt"))
        for jobnum in range(1, len(prev_lists)+1):
            tmp_filelist = prev_lists[jobnum-1]
            args = [output_file.replace(".root","_"+str(jobnum)+".root"), [tmp_filelist], options, log_file.replace(".log","_"+str(jobnum)+".log")]
            ana_arguments.append(args)
    elif opt.NEVT != -1:
        # SPLIT MODE (recommended for batch): Each jobs runs on max opt.NEVT
        options.append("fullFileList="+filelist) # Need full ntuple to correctly normalize weights
        with open(filelist) as f:
            files = f.read().splitlines()
            jobnum = 0
            totalevt = 0
            for i in range(0, len(files)):
                # First get the number of events in the file
                f = ROOT.TFile.Open(files[i])
                tree = f.Get("B2GTree")
                if not tree: tree = f.Get("B2GTTreeMaker/B2GTree")
                nevt = tree.GetEntries()
                # Create a new list after every opt.NEVT
                if i==0 or (totalevt + nevt > opt.NEVT):
                    jobnum += 1
                    tmp_filelist = filelist.replace("filelists","filelists_tmp").replace(".txt","_"+str(jobnum)+".txt")
                    args = [output_file.replace(".root","_"+str(jobnum)+".root"), [tmp_filelist], options, log_file.replace(".log","_"+str(jobnum)+".log")]
                    ana_arguments.append(args)
                    totalevt = 0
                totalevt += nevt
                with open(tmp_filelist, "a") as job_filelist:
                    job_filelist.write(os.path.realpath(files[i])+'\n')
        print "  "+filelist.replace("filelists","filelists_tmp").replace(".txt","_*.txt")+" created"
    elif opt.NFILE != -1:
        # SPLIT MODE: Each jobs runs on max opt.NFILE
        options.append("fullFileList="+filelist) # Need full ntuple to correctly normalize
        with open(filelist) as f:
            lines = f.read().splitlines()
            for n in range(1, len(lines)/opt.NFILE+2):
                tmp_filelist = filelist.replace("filelists","filelists_tmp").replace(".txt","_"+str(n)+".txt")
                with open(tmp_filelist, "w") as job_filelist:
                    for i in range((n-1)*opt.NFILE, min(n*opt.NFILE,len(lines))):
                        job_filelist.write(os.path.realpath(lines[i])+'\n')
                args = [output_file.replace(".root","_"+str(n)+".root"), [tmp_filelist], options, log_file.replace(".log","_"+str(n)+".log")]
                ana_arguments.append(args)
    else:
        # In case of a single job/dataset
        ana_arguments.append([output_file, [filelist], options, log_file])

if opt.NFILE != -1 or opt.NEVT != -1 and not opt.useprev:
    print "All temporary filelist ready."

# --------------------- Functions ------------------------
# Show and run command with stdout on screen
icommand=0
def special_call(cmd, verbose=1):
    global icommand, opt
    if verbose:
        if opt.run:
            print("[%d] " % icommand),
        else:
            print("[dry] "),
        for i in xrange(len(cmd)): print cmd[i]+" ",
        print ""
    if opt.run:
        if subprocess.call(cmd):
            print "ERROR: Problem executing command:"
            print("[%d] " % icommand)
            for i in xrange(len(cmd)): print cmd[i]+" ",
            print ""
            print "exiting."
            sys.exit()
        if verbose: print ""
    sys.stdout.flush()
    icommand+=1

# Run command with stdout/stderr saved to logfile
def logged_call(cmd, logfile):
    global opt
    if not os.path.exists(os.path.dirname(logfile)):
        special_call(["mkdir", "-p", os.path.dirname(logfile)], 0)
    if opt.run:
        logger = logging.getLogger(logfile)
        hdlr = logging.FileHandler(logfile)
        logger.addHandler(hdlr)
        logger.setLevel(logging.INFO)
        proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout, stderr = proc.communicate()
        if stdout:
            logger.info(stdout)
        if stderr:
            logger.error(stderr)
        proc.wait()
        return proc
    else:
        proc = subprocess.call(["echo", "[dry]"]+cmd+[">", logfile])
        return proc

# Compile programs
def compile(Ana = 1, Plotter = 1):
    global opt, EXEC_PATH
    print "Compiling ..."
    print
    saved_path = os.getcwd()
    if opt.run: os.chdir(EXEC_PATH)
    special_call(["make", "clean"])
    if Ana: special_call(["make", "Analyzer"])
    if Plotter: special_call(["make", "Plotter"])
    if opt.run: os.chdir(saved_path)
    print "Compilation successful."
    print

# backup files for bookkeeping
def backup_files(backup_dir):
    print "Backing up files in: "+backup_dir
    print
    special_call(["mkdir", "-p", backup_dir])
    special_call(["cp", "-rp", "pileup", "systematics", "filelists", "common", "scripts"] + glob.glob("*.h") + glob.glob("*.cc") + glob.glob("Makefile*") + [backup_dir+"/"])
    print

# Run a single Analyzer instance (on a single input list, i.e. one dataset)
#def analyzer_job((output_file, input_list, options, output_log)):
#    global opt, EXEC_PATH, COPYSCRIPT
def analyzer_job(jobindex):
    global ana_arguments, opt, EXEC_PATH, COPYSCRIPT
    output_file = ana_arguments[jobindex][0]
    input_list  = ana_arguments[jobindex][1]
    options     = ana_arguments[jobindex][2]
    output_log  = ana_arguments[jobindex][3]
    if opt.run:
        if opt.batch:
            print "Sending job to batch (queue: "+opt.QUEUE+"), expected output: "+output_file
        else:
            print "Start Analyzing, expected output: "+output_file
    if not os.path.exists(os.path.dirname(output_file)):
        special_call(["mkdir", "-p", os.path.dirname(output_file)], 0)
    cmd = [EXEC_PATH+"/Analyzer", output_file] + options + input_list
    if opt.batch:
        #cmd = shlex.split('bsub -q '+opt.QUEUE+' -o '+output_log.replace(".log","_batch.log")+' -L /bin/bash '+os.getcwd()+'/scripts/Analyzer_batch_job.sh '+os.getcwd())+cmd
        #logged_call(cmd, output_log)
        cmd = shlex.split('bsub -q '+opt.QUEUE+' -J '+DATE.split("_")[-1].split("m")[0]+'_'+str(jobindex)+' -o '+output_log+' -L /bin/bash '+os.getcwd()+'/scripts/Analyzer_batch_job.sh '+os.getcwd())+cmd
        special_call(cmd, 0)
    else:
        logged_call(cmd, output_log)
    # Mirror output (copy to EOS)
    if opt.batch: time.sleep(opt.SLEEP)
    elif opt.skim:
        outpath = output_file.split("/")[-3]+"/"+output_file.split("/")[-2]+"/"+output_file.split("/")[-1]
        if opt.mirror: logged_call(["lcg-cp", "-v", output_file, EOS_JANOS+outpath], output_log)
        elif opt.run:
            with open(COPYSCRIPT, "a") as myfile:
                myfile.write('lcg-cp -v '+output_file+' '+EOS_VIKTOR+outpath+'\n')
                #myfile.write('srm-set-permissions -type=CHANGE -group=RW '+EOS_VIKTOR+outpath+'\n')
    return output_file

# Run all Analyzer jobs in parallel
def analysis(ana_arguments, nproc):
    global opt
    njob = len(ana_arguments)
    if njob<nproc: nproc = njob
    print "Running "+str(njob)+" instances of Analyzer jobs:"
    print
    saved_path = os.getcwd()
    if opt.batch:
        # First send all jobs to batch
        output_files = []
        for i in range(0, len(ana_arguments)):
            output_files.append(analyzer_job(ana_arguments[i]))
        # Then, wait for all output files to appear
        if opt.run:
            output_missing = True
            while output_missing:
                finished = 0
                for output_file in output_files:
                    if os.path.isfile(output_file):
                        # Check size to be large enough, so it is not the first opened state
                        if (os.path.getsize(output_file) > 1000):
                            finished += 1
                output_missing = (finished != len(output_files))
                print "Analyzer jobs on batch (Done/All): "+str(finished)+"/"+str(len(output_files))+"   \r",
                sys.stdout.flush()
                if output_missing: time.sleep(30)
                else: print "\nAll batch jobs finished."
    else:
        # Use the N CPUs in parallel on the current computer to analyze all jobs
        workers = multiprocessing.Pool(processes=nproc)
        njob = ana
        output_files = workers.map(analyzer_job, ana_arguments, chunksize=1)
        workers.close()
        workers.join()
        print "All Analyzer jobs finished."
    print
    return output_files

# Run Plotter, output of Analyzer is input for this code
def plotter(input_files, output_file):
    global opt, EXEC_PATH
    print "Start plotting from output files"
    print
    special_call([EXEC_PATH+"/Plotter", output_file] + input_files)
    print "Plotting finished."
    print

def show_result(plotter_out):
    print "Showing the result in root: "
    print
    special_call(["root", "-l", 'scripts/show_result.C("'+plotter_out+'")'])

# ---------------------- Running -------------------------

if opt.replot:
    backup_files(EXEC_PATH)
    compile(0)
    plotter(PLOTTER_IN, PLOTTER_OUT)
    show_result(PLOTTER_OUT)
else:
    if not opt.test:
        backup_files(EXEC_PATH)
    compile(1, opt.plot)
    plotter_input_files = analysis(ana_arguments, opt.NPROC)
    if opt.plot:
        plotter(plotter_input_files, PLOTTER_OUT)
        show_result(PLOTTER_OUT)

print "Done."
