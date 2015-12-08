#!/bin/bash
sfml_path=""
OPTIND=1

cd dia/
dia2code Etat_Fight.dia -d ../src/FIGHT/
#dia2code Ia.dia -d ../src/IA/
#dia2code Ihm.dia -d ../src/IHM/
#dia2code Map.dia -d ../src/MAP/
dia2code Moteur.dia -d ../src/MOTEUR/
#dia2code Rendu.dia -d ../src/RENDU/
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

