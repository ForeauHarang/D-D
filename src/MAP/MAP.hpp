#ifndef MAP__HPP
#define MAP__HPP

#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <iostream>

namespace MAP{

    #define PTRNULL 0
    #define NOMBRECARAC 9
    #define NOMBRESLOTS 15 // 1 slot arme, 1 slot potion, 1 slot armure, 1 slot garbage, 1 slot transition
    #define NOMBRECOMPETENCES 6
    #define NBPERSO 6
    #define NBQUETES 10
    #define NBCOFFRES  10

    using std::string;

    enum Race { HUMAIN, LOUP_GAROU, VAMPIRE, MONSTRE };
    enum Profession { SOLDAT, VOLEUR, SORCIER };
    enum Groupe { NEUTRE, GENTIL, MECHANT };
    enum NomObjet {PASDENOM, COUTEAU, PISTOLET, FUSIL, VETEMENT, KELVAR, POTION_SOIN, POTION_MANA, POISON, LIVRE, POULET, BALLES_ARGENTS, SAC_SANG, PIEUX };
    enum TypeObjet { PASDETYPE, ARME, ARMURE, POTION, QUETE };
    enum EtatQuete { REPOS, ENCOURS, TERMINEE, REMISE, RATEE };
    class MAP_Carte;
    class MAP_Coffre;
    class MAP_InventairePersonnage;
    class MAP_ObjetInventaire;
    class MAP_Personnage;
    class MAP_Quete;



}


#include "MAP.h"



#endif