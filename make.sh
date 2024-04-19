#!/bin/env bash



# needs root to write to /usr/local/include/... and /usr/local/lib/...
[[ "$EUID" -ne 0 ]] && echo "must be run as root" && exit 1



####  CONFIG  ####

# target directory for the header files to be copied to
INCLUDE_DIR="/usr/local/include/soph"

# target directory for the final lib file to be copied to
LIBRARY_DIR="/usr/local/lib"

# project root, $(pwd) works as long as you run this script in the root directory of the project
PROJ_ROOT=$(pwd)

# filename for the final lib file
TARGET="libsoph"



####  LOGIC  ####

# make sure config settings are good
[[ -z "$PROJ_ROOT" ]] && echo "PROJ_ROOT is not set" && exit 1
[[ -z "$INCLUDE_DIR" ]] && echo "INCLUDE_DIR is not set" && exit 1
[[ -z "$LIBRARY_DIR" ]] && echo "LIBRARY_DIR is not set" && exit 1
[[ -z "$TARGET" ]] && echo "TARGET is not set" && exit 1

# copy headers to $INCLUDE_DIR
cp -r "$PROJ_ROOT/include/"*.h "$INCLUDE_DIR"

# if the temporary directory `$PROJ_ROOT/build` does not exist, create it
[[ ! -d "$PROJ_ROOT/build" ]] && mkdir "$PROJ_ROOT/build/"

# enter the build directory and compile all the sources into object files
cd "$PROJ_ROOT/build/" && gcc -c "$PROJ_ROOT/src/"*.c -lm # -O2

# link the built object files together into the final lib file
ar rcs "$PROJ_ROOT/build/$TARGET.a" "$PROJ_ROOT/build/"*.o

# copy the lib file into $LIBRARY_DIR
cp "$PROJ_ROOT/build/$TARGET.a" "$LIBRARY_DIR"

# remove the temporary build directory
rm -rf "$PROJ_ROOT/build"

