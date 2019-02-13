## What is `profile.sh`?
Souffle generates C++ code given a datalog program and `profile.sh` shows which C++ functions take up the bulk of the runtime when the C++ code is executed. It shows the percentage time spent in each of these functions and number of calls.
## How do I use it?
You need to specify the facts directory, a souffle instance, and a datalog program. You can also get readable output with the `--pretty` or `-p` flag. Here is an example:

`./profile.sh my_fave.dl --instance=/home/souffle/src/souffle --facts=/crap/facts --pretty`. Or with short options,
`./profile.sh thingo.dl -I /home/souffle -F facts -p`. Have fun!!!!
