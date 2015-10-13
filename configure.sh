#!/bin/bash
sfml_path=""
OPTIND=1


rm -r build
mkdir build
cd build/

if ["$sfml_path" == ""]; then
	echo "Trying default SMFL autodetect"
	cmake ..
else
	echo "Using custom SFML location"
	cmake .. -DSFML_ROOT=$sfml_path
fi
cd ../bin
./vandw

