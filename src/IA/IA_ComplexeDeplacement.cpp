#include "IA.hpp"

using namespace IA;
using namespace MOTEUR;
using namespace MAP;

IA_ComplexeDeplacement::IA_ComplexeDeplacement(MOTEUR_ListeAction* actions, MAP_Personnage* ia, MAP_Carte* map){
    this->actions=actions;
    this->ia=ia;
    this->map = map;
    liste.push_back(new IA_DeplacementCase(0, ia->getX(), ia->getY(), this->map));

}
void IA_ComplexeDeplacement::addChildrenToList(IA_DeplacementCase* pere) {
    int etage = pere->getStage();
    int x = pere->getX();
    int y = pere->getY();

    if (x < 66) {
        IA_DeplacementCase *fils1 = new IA_DeplacementCase(etage + 1, x + 1, y, pere, pere->getMap());
        liste.push_back(fils1);
    }
    if(x>0) {
        IA_DeplacementCase *fils2 = new IA_DeplacementCase(etage + 1, x - 1, y, pere, pere->getMap());
        liste.push_back(fils2);
    }
    if(y>0){
        IA_DeplacementCase* fils3 = new IA_DeplacementCase(etage+1, x, y-1, pere, pere->getMap());
        liste.push_back(fils3);
    }
    if(y<22){
        IA_DeplacementCase* fils4 = new IA_DeplacementCase(etage+1, x, y+1, pere, pere->getMap());
        liste.push_back(fils4);
    }

}
void IA_ComplexeDeplacement::reachTarget(int xCible, int yCible, int i){
    distanceMin=liste[0]->getSquareDistance(xCible, yCible, map);

    if(liste[0]->getX()==xCible && liste[0]->getY()==yCible){
        indiceDistanceMin=0;
        distanceMin=0;
    }else{

        while(i<1023) {
            int d = liste[i]->getSquareDistance(xCible, yCible, map);
            if (d < 0) {

            } else {

                if (distanceMin < 0) {
                    distanceMin = d;

                }
                if (distanceMin < d) {

                } else {
                    distanceMin = d;
                    indiceDistanceMin = i;

                }
                if(d==0){
                    break;
                }

                addChildrenToList(liste[i]);
            }

            i++;
        }

    }

    if(distanceMin>=0){
        addAction();
    }
    int distanceMin=-1;
    int indiceDistanceMin=0;

    liste.erase(liste.begin(), liste.begin()+liste.size());

}
void IA_ComplexeDeplacement::addAction(){
    IA_DeplacementCase* temp = liste[indiceDistanceMin];

    while(temp->getStage()>1){
        temp=temp->getFather();
    }
    if(temp->getStage()) {
        MOTEUR_DeplacementPersonnage *tempAction = new MOTEUR_DeplacementPersonnage();
                tempAction->initDeplacement((-liste[0]->getX() + temp->getX()) * TAILLEBLOC, (-liste[0]->getY() + temp->getY()) * TAILLEBLOC, ia);
        actions->addAction(tempAction);

    }

}
