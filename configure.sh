#!/bin/bash
sfml_path=""
OPTIND=1

cd dia/

cd ../src/FIGHT
rm *.h
cd ..
cd ..
cd dia
dia2code Etat_Fight.dia -d ../src/FIGHT/

cd ../src/IA
rm *.h
cd ..
cd ..
cd dia
dia2code IA.dia -d ../src/IA/

cd ../src/IHM
rm *.h
cd ..
cd ..
cd dia
dia2code IHM.dia -d ../src/IHM/

cd ../src/MAP
rm *.h
cd ..
cd ..
cd dia
dia2code Etat_Map.dia -d ../src/MAP/

cd ../src/MOTEUR
rm *.h
cd ..
cd ..
cd dia
dia2code Moteur.dia -d ../src/MOTEUR/

cd ../src/RENDU
rm *.h
cd ..
cd ..
cd dia
dia2code Rendu.dia -d ../src/RENDU/


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

