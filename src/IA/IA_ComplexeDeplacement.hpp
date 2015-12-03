//
// Created by gabriel on 03/12/15.
//

#ifndef INC_3A_IA_DEPLACEMENTDUR_HPP
#define INC_3A_IA_DEPLACEMENTDUR_HPP

#include "IA_DeplacementCase.hpp"
#include "../MOTEUR/MOTEUR_ListeAction.hpp"
#include "../MOTEUR/MOTEUR_DeplacementPersonnage.hpp"
#include "../MAP/MAP_Personnage.hpp"
#include "../MAP/MAP_Carte.hpp"

class IA_ComplexeDeplacement {

    private:
        int distanceMin=-1;
        int indiceDistanceMin=0;
        std::vector<IA_DeplacementCase*> liste;
        MOTEUR_ListeAction *actions;
        MAP_Personnage* ia;
        MAP_Carte* map;

    public :
        IA_ComplexeDeplacement(MOTEUR_ListeAction* actions, MAP_Personnage* ia, MAP_Carte* map);
        void addChildrenToList(IA_DeplacementCase* pere);
        void reachTarget(int xCible, int yCible, int i);
        void addAction();
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

#endif //INC_3A_IA_DEPLACEMENTDUR_HPP
