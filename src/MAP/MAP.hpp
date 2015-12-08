#ifndef MAP__HPP
#define MAP__HPP


namespace MAP{
    #include <string>
    #include <fstream>
    #include <vector>
    #include <cstdlib>
    #include <stdexcept>

    #define PTRNULL 0
    #define NOMBRECARAC 9
    #define NOMBRESLOTS 15 // 1 slot arme, 1 slot potion, 1 slot armure, 1 slot garbage, 1 slot transition
    #define NOMBRECOMPETENCES 6
    #define NBPERSO 6
    #define NBQUETES 10
    #define NBCOFFRES  10

    using std::string;


    class MAP_Carte;
    class MAP_Coffre;
    class MAP_InventairePersonnage;
    class ObjetInventaire;
    class MAP_Personnage;
    class MAP_Quete;
}


#include "MAP.h"



#endif