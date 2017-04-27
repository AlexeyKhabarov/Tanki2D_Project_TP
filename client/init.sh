#!bin/bash

sudo apt install libsfml-dev

mkdir build && cd $_
cmake ..
make
./binary

