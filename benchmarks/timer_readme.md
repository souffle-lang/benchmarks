`timer.sh` gives you statistics related to the compilation time of your datalog program given a set of facts and an instance of souffle. It also prints output in a readable format when provided with the flag `--pretty` or `-p`.

## How do I use `./timer.sh`?
When you call `./timer.sh`, you need to specify the facts directory,

`-F example.facts`
`--facts=example.facts`

and an instance of souffle,

`--instance=/home/user/souffle/src/souffle`
`-I /home/user/souffle/src/souffle`

And provide the path to your datalog program. Here are a few examples:

`./timer.sh myprogram.dl --instance=/home/dog/souffle/src/souffle --facts=wow.facts`
`./timer.sh wow.dl -I /home/souffle -F facts`

### What does the output mean?
The columns mean the following:

program name, datalog to c++ compilation time real, user, sys, max memory usage, c++ to .o compilation time real, user, sys, max memory usage, runtime of final executable real, user, sys, max memory usage


