#/bin/bash

set -e

g++ -I./externals -std=c++23 main.cpp -o a.out

if [ -f a.out ]; then
    chmod 777 a.out
    # ./a.out
    echo "sucess"
else
    echo "fail"
fi
