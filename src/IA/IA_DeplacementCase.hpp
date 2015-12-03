//
// Created by gabriel on 03/12/15.
//

#ifndef INC_3A_IA_DEPLACEMENTCASE_HPP
#define INC_3A_IA_DEPLACEMENTCASE_HPP


#define TAILLEBLOC 32

#include <vector>
#include <iostream>
#include "../MAP/MAP_Carte.hpp"

class IA_DeplacementCase {
private :
    int etage;
    IA_DeplacementCase* pere;
    int x;
    int y;
    MAP_Carte* carte;

    int i=0;

public :

    /*
    * constructeurs
    * */
    IA_DeplacementCase(int etage, int x, int y, MAP_Carte* carte);
    IA_DeplacementCase(int etage, int x, int y, IA_DeplacementCase* pere, MAP_Carte* carte);

    /*
    * destructeurs
    * */

    ~IA_DeplacementCase();

    /*
    * getteurs
    * */

    int getX();
    int getY();

    int getSquareDistance(int x, int y, MAP_Carte* map);
    int getSquareDistance(IA_DeplacementCase* cible, MAP_Carte* map);
    int getStage();
    IA_DeplacementCase* getFather();
    MAP_Carte* getMap();



    /*
    * setteurs
    * */

    /*
    * autres méthodes
    * */

};

/*
void IA_DeplacementCase::addChildrenToList(std::vector<IA_DeplacementCase*>*listeDeplacementCase){
    IA_DeplacementCase fils1(etage+1, x+1, y, this, carte);
    listeDeplacementCase->push_back(&fils1);
    IA_DeplacementCase fils2(etage+1, x-1, y, this, carte);
    listeDeplacementCase->push_back(&fils2);
    IA_DeplacementCase fils3(etage+1, x, y-1, this, carte);
    listeDeplacementCase->push_back(&fils3);
    IA_DeplacementCase fils4(etage+1, x, y+1, this, carte);
    listeDeplacementCase->push_back(&fils4);
}

*/

#endif //INC_3A_IA_DEPLACEMENTCASE_HPP
