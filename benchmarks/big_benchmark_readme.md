## What is `big_benchmark.sh`?
You should be able to run this and provide the path to a souffle executable as the sole argument. This will run `timer.sh` for each doop benchmark program listed in the `big_benchmark.sh` file. I kind of forgot which ones I picked, I think it's just all of them. (Antlr, Xalan, Hsqldb, Bloat, Eclipse, etc). So in the end, `big_benchmark.sh` will provide rows of output from `timer.sh` for each of these programs.

So in summary, you can run it like this:
  `./big_benchmark.sh /home/daniel/souffle/src/souffle`

If you want some output that is immediately readable, You can add the `--pretty` flag to your own version of the script in the call to `timer.sh`.
