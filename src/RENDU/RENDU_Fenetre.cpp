#include "RENDU_Fenetre.hpp"

/*
* constructeurs
* */
RENDU_fenetre::RENDU_fenetre(sf::RenderWindow* window) {
	this->window = window;

}

/*
* Destructeurs
* */
RENDU_fenetre::~RENDU_fenetre() {

	
}

/*
* Méthodes
* */
void RENDU_fenetre::afficherElementGraphique() {
	int i;
	for (i = 0; i < listeElementGraphique->size(); i++) {
		if (listeElementGraphique[i]->getElemId() == 1) {
			if (!(dynamic_cast <TileMap*> (listeElementGraphique[i])->load("../res/images/petiteimages.jpeg", sf::Vector2u(TAILLEBLOC, TAILLEBLOC), map1->getMap(), map1->getWidthMap(), map1->getHeightMap())) {
				std::cout << "erreur chargement image Tilemap " << std::endl;
			}
			else {
				window->draw(listeElementGraphique[i]);
			}
		}
	}
}

void RENDU_fenetre::afficherFenetre() {
	window->clear();
	afficherElementGraphique();
	window->display();
}
