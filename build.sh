#!/bin/sh

set -e
# -lm means link to math lib
cc  -Wall -Wextra -Iinclude -o imgToRaw src/main.c -lm