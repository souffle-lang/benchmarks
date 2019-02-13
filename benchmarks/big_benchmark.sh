#!/bin/bash
OUTDIR=""
SOUFFLE=""

programs=(antlr bloat jython chart eclipse fop hsqldb pmd xalan)
programs_small=(antlr eclipse xalan)
setting="2-object-sensitive+heap"
 
options=$(getopt -o I:o:h --long instance:,outdir:,help -- "$@")
eval set -- "$options"

while true ; do
  case "$1" in
    --instance|-I)  SOUFFLE=$2
                    shift
                    ;;
     --outdir|-o)   OUTDIR=$2
	     	    shift
                    ;;
     --help|-h)	    echo "Usage: $0 --instance=<SOUFFLE EXECUTABLE> --outdir=<OUTPUT DIRECTORY>"
	            exit
	     	    ;;
     --)            shift; break ;;
  esac
  shift
done

if ! [[ $SOUFFLE && $OUTDIR ]] ; then
	echo "Usage: $0 --instance=<SOUFFLE EXECUTABLE> --outdir=<OUTPUT DIRECTORY>"
	exit 1
fi

## silently create the directory if it doesn't exist!
mkdir -p $OUTDIR

## NOW START RUNNING THE BENCHMARKS
for program in ${programs_small[@]}; do
  src=$setting/souffle-$program

  if [ ! -f $OUTDIR/$program.csv ]; then
     echo "name,d2creal,d2cuser,d2csys,d2cmem,c2oreal,c2ouser,c2osys,c2omem,runreal,runuser,runsys,runmem" > $OUTDIR/$program.csv
  fi

  ./timer.sh $src/$setting.dl -I $SOUFFLE -F $src/facts >> $OUTDIR/$program.csv
done

