#include "RENDU.hpp"
using namespace MAP;
using namespace RENDU;

/*
* constructeurs
* */
RENDU_Fenetre::RENDU_Fenetre(sf::RenderWindow* window, MAP_Carte* map1) {
	this->window = window;
	this->map1=map1;

}

/*
* Destructeurs
* */
RENDU_Fenetre::~RENDU_Fenetre() {

	
}

/*
* Methodes
* */
void RENDU_Fenetre::afficherElementGraphique(){
	int i;

	for (i = 0; i < listeElementGraphique.size(); i++) {

		if (listeElementGraphique[i]->getElemId() == "TileMap") {

			if (!((dynamic_cast<TileMapnew*>(listeElementGraphique[i]))
					->load("../res/images/petiteimages.jpeg",
						   sf::Vector2u(TAILLEBLOC, TAILLEBLOC),
						   map1->getMap(), (unsigned)map1->getWidthMap(),
						   (unsigned)map1->getHeightMap()))) {
				std::cout << "erreur chargement image Tilemap " << std::endl;
			}
			else {
				
				window->draw(*listeElementGraphique[i]);
			}
		}else{
			sf::Texture textureTemp;
			sf::Sprite spriteTemp;
			textureTemp.loadFromFile(dynamic_cast <RENDU_Sprite*>(listeElementGraphique[i])->getElementString());


			
			spriteTemp.setTexture(textureTemp);
			spriteTemp.setTextureRect(sf::IntRect(0,TAILLEBLOC, TAILLEBLOC, TAILLEBLOC));
			
			spriteTemp.setPosition(dynamic_cast <RENDU_Sprite*> (listeElementGraphique[i])->getCharacterPtr()->getX(),dynamic_cast <RENDU_Sprite*> (listeElementGraphique[i])->getCharacterPtr()->getY());

			window->draw(spriteTemp);
		}
	}
}

void RENDU_Fenetre::afficherFenetre() {
	window->clear();

	afficherElementGraphique();

	window->display();
}

void RENDU_Fenetre::addElementToList(RENDU_ElementGraphique* element){
	if(!element) throw std::invalid_argument("RENDU_Fenetre::addElementToList");

	listeElementGraphique.push_back(element);


}
/*
void RENDU_Fenetre::removeElementFromList(std::string name){
	
}
* */
