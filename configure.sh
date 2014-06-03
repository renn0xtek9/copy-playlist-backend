#!/bin/bash
options=`more BUILDCHAIN.conf | grep OPTIONS_TO_CMAKE | sed 's/OPTIONS_TO_CMAKE=//'`
echo "Passing to cmake: $options "
mkdir -p build 
cd ./build 
rm -r -f *
cmake .. $options
make