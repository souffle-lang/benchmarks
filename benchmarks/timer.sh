## these are the variables that need to be populated in order for the program to run
## and produce meaningful output
SOUFFLE=""
FACTS=""
PROGRAM=""
PRETTY=false
OPTIONS=""

######################################
## Uses the usual output
## from the simple function and formats it
pretty() {
  OLDIFS=$IFS
  IFS=","
  # some colours
  NOCOLOUR='\033[0m'
  RED='\033[0;31m'
  YELLOW='\033[1;33m'
  PURPLE='\033[0;35m'

  local temp=$(mktemp /tmp/tmp.XXXXX)
  simple > $temp

  while read name d2creal d2cuser d2csys d2cmem c2oreal c2ouser c2osys c2omem runreal runuser runsys runmem
    do
      echo -e "${RED}=====$name==============================="
      echo -e "${PURPLE}\tDatalog -> C++"
      echo -e "${NOCOLOUR}\t\tReal:\t$d2creal s\n\t\tUser:\t$d2cuser s\n\t\tSystem:\t$d2csys s\n\t\tMemory usage:\t$d2cmem kB"
      echo -e "${PURPLE}\tC++ -> .o"
      echo -e "${NOCOLOUR}\t\tReal:\t$c2oreal s\n\t\tUser:\t$c2ouser s\n\t\tSystem:\t$c2osys s\n\t\tMemory usage:\t$c2omem kB"
      echo -e "${PURPLE}\tRunning..."
      echo -e "${NOCOLOUR}\t\tReal:\t$runreal s\n\t\tUser:\t$runuser s\n\t\tSystem:\t$runsys s\n\t\tMemory usage:\t$runmem kB"
  done < $temp
  rm $temp
  IFS=$OLDIFS
}

######################################
## Does everything, 
## outputs a csv to stdout
simple() {
  local temp_file=$(mktemp XXXXXX)
  local output=$(mktemp XXXXX)
  # put necessary permissions
  chmod +x $output
  chmod +x $SOUFFLE-compile

  printf "$PROGRAM,"
  
  { /usr/bin/time -f "%e,%U,%S,%M" \
  timeout 15m \
  $SOUFFLE $PROGRAM \
  -F $FACTS \
  -w \
  -g $output.cpp $OPTIONS; } &> $temp_file
  ## get rid of the bloody trailing newline that time causes
  perl -pi -e 'chomp if eof' $temp_file

  ## this is for cpp->.o
  { /usr/bin/time \
  -f  ",%e,%U,%S,%M" \
  $SOUFFLE-compile $output.cpp; } &>> $temp_file
  perl -pi -e 'chomp if eof' $temp_file
  
  ## this is for the actual execution
  { /usr/bin/time \
  -f ",%e,%U,%S,%M" \
  timeout 15m \
  ./$output > /dev/null; } &>> $temp_file

  cat $temp_file
  rm $temp_file $output $output.cpp 
}

## The main function, dealing with flags and
## just populating the variables we need

options=$(getopt -o pF:I: --long pretty,instance:,facts: -- "$@")
eval set -- "$options"

while true ; do
  case "$1" in
     --pretty|-p)   PRETTY=true 
                    ;;
     --facts|-F)    FACTS=$2 
                    shift 
                    ;; 
     --instance|-I) SOUFFLE=$2 
                    shift 
                    ;;
     --)            shift; break ;;
  esac
  shift 
done

# now the datalog program should be the only thing left 
# over (it's after the --)
PROGRAM=$1

if ! [[ $PROGRAM && $SOUFFLE && $FACTS ]] ; then
# make sure theyre all set to something not fake
  echo "Usage: $0 FILE --facts=<FILE> --instance=<SOUFFLE_PATH>"
  exit 1
fi

if $PRETTY; then
  pretty
else
  simple
fi



