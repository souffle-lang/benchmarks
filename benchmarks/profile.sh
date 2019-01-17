# Give a pointer to the Souffle instance --instance=/home/rdow6615/souffle/src/souffle
# Give a .dl file as an argument also
# Give a fact file with --facts=blah.facts or -F blah.facts 
# GLOBAL VARIABLES
SOUFFLE=""
DATALOG_FILE=""
FACTS=""
PRETTY=false

## pretty() calls simple and just uses 
## the data produced to print something readable.
pretty() {
  local temp=$(mktemp /tmp/tmp.XXXXXX)
  simple > $temp
  while read percentage numcalls name 
    do
      echo -e "\e[1;33m$percentage% of $1 runtime\
      ==============================================================================================\e[0m\n\
      Function:\t ${name:0:100}...\n\
      Number of Calls:\t $numcalls\n"
    done < $temp
    rm "$temp"
}


simple() {
  local output=$(mktemp XXXX)
# 1. compile the .dl file
  CPPFLAGS="-pg" $SOUFFLE $DATALOG_FILE -F $FACTS -w -o $output
# 2. run it and suppress the output
  ./$output > /dev/null
# 3. Run gprof
  local temp=$(mktemp /tmp/tmp1.XXXXXX)
  gprof $output gmon.out --flat-profile --brief > $temp
# delete first rubbish lines
  sed -i -e 1,5d $temp

#  echo "this is the output of flat profile"
#  cat $temp
#
  while read percentage cumulative self calls selfmscall totalmscall name      
    do
      percentageAsInteger=`echo "$percentage/1" | bc`
      if [ $percentageAsInteger -gt 1 ] ; then
        echo -e "$percentage\t$calls\t$name"
      fi
    done < $temp

  rm "$temp" "$output"
}

## deal with flags

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

## Now it should have skipped over the --, 
## the next one will be the datalog file name
DATALOG_FILE=$1

if ! [[ $DATALOG_FILE && $SOUFFLE && $FACTS ]] ; then
# make sure theyre all set to something not fake
  echo "Usage: ./profile.sh FILE --facts=<FILE> --instance=<SOUFFLE_PATH>"
  exit 1
fi

if $PRETTY; then
  pretty
else
  simple
fi
