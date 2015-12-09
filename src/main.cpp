/*#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <thread>

#include "FIGHT/FIGHT_Carte.hpp"
#include "RENDU/TileMapnew.hpp"
#include "MAP/MAP_Carte.hpp"
#include "MAP/MAP_Personnage.hpp"
#include "MAP/MAP_VariablesGlobales.hpp"
#include "MOTEUR/MOTEUR_DeplacementPersonnage.hpp"
#include "MOTEUR/MOTEUR_ListeAction.hpp"
#include "RENDU/RENDU_Fenetre.hpp"
#include "RENDU/TileMapnew.hpp"
#include "IHM/IHM_PersonnageControleur.hpp"
#include "IA/IA_IASimple.hpp"
#include "IA/IA_ComplexeDeplacement.hpp"


#define TAILLEBLOC 32


void helloWorld(){
	std::cout<<"Hello World !"<<std::endl;
}
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <thread>

#define TAILLEBLOC 32

#include "MAP/MAP.hpp"
#include "FIGHT/FIGHT.hpp"
#include "RENDU/RENDU.hpp"
#include "IA/IA.hpp"
#include "IHM/IHM.hpp"
#include "MOTEUR/MOTEUR.hpp"

using namespace MAP;
using namespace FIGHT;
using namespace RENDU;
using namespace IA;
using namespace IHM;
using namespace MOTEUR;


// on crée la fenêtre
sf::RenderWindow window(sf::VideoMode(1350, 800), "Tilemap");

int main() {
	int id = 1;
	MAP_Carte map1(id, 67, 23);

	MOTEUR_ListeAction actions(&map1);

	RENDU_Fenetre fenetre(&window, &map1);

	IHM_PersonnageControleur ihm(&map1, &actions);

	IA_IASimple ia(&map1, &actions);



	TileMapnew tilemap;
	tilemap.setMap(&map1);
	//std::cout << tilemap.getElemId() << std::endl;

	fenetre.addElementToList(&tilemap);

	//Personnage Principal - map1.getListCharacters()[0] - perso

	//MAP_InventairePersonnage inventairePrincipal=MAP_InventairePersonnage();
	std::string bob = "bob";
	//Race hum = HUMAIN;
	//Profession sold = SOLDAT;
	//Groupe gentil=GENTIL;
	MAP_Personnage persoPrincipal = MAP_Personnage(bob);
	MAP_Personnage *ptrpersoPrincipal = &persoPrincipal;
	persoPrincipal.setX(8 * TAILLEBLOC);
	persoPrincipal.setY(8 * TAILLEBLOC);
	map1.addCharacter(ptrpersoPrincipal);
	map1.getListCharacters().push_back(ptrpersoPrincipal);
	RENDU_Sprite sprite1("../res/images/vampire.png", "bob", ptrpersoPrincipal);
	fenetre.addElementToList(&sprite1);

	//Personnage 2 - map1.getListCharacters()[1] - perso2

	//MAP_InventairePersonnage inventaire2 = MAP_InventairePersonnage();
	std::string bobMaman = "bobMaman";
	//Race hum2 = VAMPIRE;
	//Profession sold2 = SOLDAT;
	//Groupe gentil2 = GENTIL;
	MAP_Personnage perso2 = MAP_Personnage(bobMaman);
	MAP_Personnage *ptrperso2 = &perso2;
	perso2.setX(15 * TAILLEBLOC);
	perso2.setY(15 * TAILLEBLOC);
	map1.addCharacter(ptrperso2);
	map1.getListCharacters().push_back(ptrperso2);
	RENDU_Sprite sprite2("../res/images/Loup-garou.png", "bobMaman", ptrperso2);
	fenetre.addElementToList(&sprite2);

	// Event possibles :
	std::cout << "Vous pouvez :" << std::endl;
	std::cout << "Aller a droite : Touche D" << std::endl;
	std::cout << "Aller a gauche : Touche Q" << std::endl;
	std::cout << "Aller en haut : Touche Z" << std::endl;
	std::cout << "Aller en bas : Touche S" << std::endl;
	std::cout << "Fermer la fenetre : Touche Echap ou la croix" << std::endl;


	//IA_ComplexeDeplacement IAComplexeDeplacement(&actions, ptrperso2, &map1);


	std::thread tMoteurJeu(&MOTEUR_ListeAction::apply, &actions);

	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen()) {

		fenetre.afficherFenetre();
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		while (window.pollEvent(event)) {

			//Event du clavier pour déplacement d'un joueur
			ihm.deplacementCommande(event);
			//Event pour fermer la fenêtre 
			ihm.fermerFenetre(event, &window);

		}

		IA_ComplexeDeplacement IAComplexeDeplacement(&actions, ptrperso2, &map1);
		//std::cout<<"x="<<(map1.getListCharacters()[0]->getX()-map1.getListCharacters()[1]->getX())/TAILLEBLOC<<std::endl;
		IAComplexeDeplacement.reachTarget(map1.getListCharacters()[0]->getX() / TAILLEBLOC,
										  map1.getListCharacters()[0]->getY() / TAILLEBLOC, 0);

		//IA simple
		//iaSimple(map1, actions);

		//ia.reachTarget(&map1, map1.getListCharacters()[0]->getX(), map1.getListCharacters()[0]->getY(), map1.getListCharacters()[1]->getX(), map1.getListCharacters()[1]->getY());



		//actions.apply();

	}
	if (tMoteurJeu.joinable()){
		tMoteurJeu.join();
	}
    return 0;
}