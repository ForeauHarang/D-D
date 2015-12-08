#!/bin/bash
sfml_path=""
OPTIND=1

cd dia/
dia2code Etat_Fight.dia -d ../src/FIGHT/
dia2code Moteur.dia -d ../src/MOTEUR/

cd ..

rm -r bin
mkdir bin
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
make
cd ../bin
./vandw

