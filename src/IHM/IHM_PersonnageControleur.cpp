#include "IHM_PersonnageControleur.hpp"

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

	//Si la touche D est appuyée, aller à droite
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::D)) {
		action = new MOTEUR_DeplacementPersonnage(TAILLEBLOC, 0, (map->getListCharacters()[0]));
		actions->addAction(action);
	}
	//Si la touche Q est appuyée, aller à gauche
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Q)) {
		action =new MOTEUR_DeplacementPersonnage(-TAILLEBLOC, 0, (map->getListCharacters()[0]));
		actions->addAction(action);
	}
	//Si la touche Z est appuyée, aller en haut
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Z)) {
		action =new MOTEUR_DeplacementPersonnage(0, -TAILLEBLOC, (map->getListCharacters()[0]));
		actions->addAction(action);
	}
	//Si la touche S est appuyée, aller en bas
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::S)) {
		action =new MOTEUR_DeplacementPersonnage(0, TAILLEBLOC, (map->getListCharacters()[0]));
		actions->addAction(action);
	}
	//actions->apply();
}

void IHM_PersonnageControleur::fermerFenetre(sf::Event event, sf::RenderWindow* window) {
	//Si la touche Echape est appuyée ou la croix rouge cliquée, fermé
	if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Escape) || event.type == sf::Event::Closed) {
		window->close();
	}
}

