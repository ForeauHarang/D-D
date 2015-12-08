#ifndef MOTEUR_VariablesGlobales_HPP
#define MOTEUR_VariablesGlobales_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdio>

// Catégorie commande
enum  CategorieCommande{CATEGORIE_PRINCIPALE = 0x100, 
						CATEGORIE_DEPLACEMENT = 0x200,
						CATEGORIE_MODE = 0x300};
						


// Commande id
enum  IdCommande{CHARGEMENT = 1, 
						MODE = 2,
						DIRECTION = 3};


// Moteur mode
enum  ModeMoteur{PLAY = 1, 
				 RECORD = 2,
				 PAUSE = 3,
				 REPLAY = 4,
				 CLOSE = 5};

#endif
