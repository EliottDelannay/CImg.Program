#! /bin/bash

#get display help output (xterm-color unformated)
bin=./CImg.operation
out=CImg.operation.help
$bin -h 2> $out; cat -v $out | sed 's/\^\[\[//g' | sed 's/1m//g' | sed 's/0;0;0m//g' | sed 's/0;35;59m//g' | sed 's/4;31;59m//g' | sed 's/0;32;59m//g' > $out.output; rm $out

#create documentation
doxygen operation.Doxygen

