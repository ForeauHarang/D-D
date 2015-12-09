#include "IHM.hpp"
using namespace IHM;
using namespace MOTEUR;
/*
* Contructeur
*/
IHM_PersonnageControleur::IHM_PersonnageControleur(MAP_Carte* map, MOTEUR_ListeAction* actions) {
	this->actions = actions;
	this->map = map;
}

IHM_PersonnageControleur::~IHM_PersonnageControleur() {

}

void IHM_PersonnageControleur::deplacementCommande(sf::Event event) {
	MOTEUR_DeplacementPersonnage* action;

	//Si la touche D est appuy�e, aller � droite
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::D)) {
		action = new MOTEUR_DeplacementPersonnage();
		action->initDeplacement(TAILLEBLOC, 0, (map->getListCharacters()[0]));
		actions->addAction(action);
	}
	//Si la touche Q est appuy�e, aller � gauche
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Q)) {
		action =new MOTEUR_DeplacementPersonnage();
		action->initDeplacement(-TAILLEBLOC, 0, (map->getListCharacters()[0]));
		actions->addAction(action);
	}
	//Si la touche Z est appuy�e, aller en haut
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Z)) {
		action =new MOTEUR_DeplacementPersonnage();
		action->initDeplacement(0,-TAILLEBLOC, (map->getListCharacters()[0]));
		actions->addAction(action);
	}
	//Si la touche S est appuy�e, aller en bas
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::S)) {
		action =new MOTEUR_DeplacementPersonnage();
		action->initDeplacement(0, TAILLEBLOC, (map->getListCharacters()[0]));
		actions->addAction(action);
	}
	//actions->apply();
}

void IHM_PersonnageControleur::fermerFenetre(sf::Event event, sf::RenderWindow* window) {
	//Si la touche Echape est appuy�e ou la croix rouge cliqu�e, ferm�
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Escape) || event.type == sf::Event::Closed) {
		MOTEUR_QuitterProgramme* action;
		action=new MOTEUR_QuitterProgramme();
		action->setWindow(window);
		actions->addAction(action);
		window->close();
	}
}

