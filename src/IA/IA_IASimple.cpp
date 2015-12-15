#include "IA.hpp"

using namespace IA;
using namespace MOTEUR;
using namespace MAP;

#define TAILLEBLOC 32

/*
* Contructeur
*/
IA_IASimple::IA_IASimple(MAP_Carte* map, MOTEUR_ListeAction* actions):IA_Manager() {
	this->actions = actions;
	this->map = map;
}

/*
* Destructeur
*/
/*IA_IASimple::~IA_IASimple() {

}*/

/*
* Methodes
*/

// (x1,y1) : cible / (x2,y2) : objet qui atteint la cible
void IA_IASimple::reachTarget(MAP_Carte* map, int X1, int Y1, int X2, int Y2) {
	MOTEUR_DeplacementPersonnage* action;

	int dx = 0;
	int	dy = 0;
	int signe = 0;
		
	/*X1 = map->getListCharacters()[0]->getX();
	Y1 = map->getListCharacters()[0]->getY();
	X2 = map->getListCharacters()[1]->getX();
	Y2 = map->getListCharacters()[1]->getY();*/

	/*if (X1 == X2 && Y1 == Y2) {
	}
	else*/
	if ((X1 - X2)*(X1 - X2)<(Y1 - Y2)*(Y1 - Y2)) {
		dy = TAILLEBLOC;
		if (Y1<Y2) {
			signe = -1;
		}
		else if (Y1 == Y2) {

		}
		else {
			signe = 1;
		}
		action =new MOTEUR_DeplacementPersonnage();
		action->initDeplacement(signe*dx, signe*dy, (map->getListCharacters()[1]));
		actions->addAction(action);

	}
	else {
		dx = TAILLEBLOC;
		if (X1<X2) {
			signe = -1;
		}
		else if (X1 == X2) {
		}else {
			signe = 1;
		}
		action = new MOTEUR_DeplacementPersonnage();
		action->initDeplacement(signe*dx, signe*dy, (map->getListCharacters()[1]));
		
		actions->addAction(action);
	}
	
	//std::cout << actions->getActionFromList(0)<< std::endl;
	//actions.apply();
}
