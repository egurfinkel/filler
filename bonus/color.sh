!/bin/bash

O=$(echo "\033[0;32mO\033[0m")
o=$(echo "\033[1;32mo\033[0m")
X=$(echo "\033[0;33mX\033[0m")
x=$(echo "\033[1;33mx\033[0m")

cat \
    | sed "s|O|$O|g" \
    | sed "s|o|$o|g" \
    | sed "s|X|$X|g" \
    | sed "s|x|$x|g" \