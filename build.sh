#!/bin/sh

set -e
# -lm means link to math lib
cc  -Wall -Wextra -Iinclude -o img2raw src/main.c -lm