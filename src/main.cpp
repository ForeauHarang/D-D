#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "FIGHT/FIGHT_Carte.hpp"
#include "RENDU/TileMap.hpp"
#include "MAP/MAP_Carte.hpp"
#include "MAP/MAP_Personnage.hpp"
#include "MAP/MAP_VariablesGlobales.hpp"
#include "MOTEUR/MOTEUR_DeplacementPersonnage.hpp"
#include "MOTEUR/MOTEUR_ListeAction.hpp"
#include "RENDU/RENDU_Fenetre.hpp"
#include "RENDU/TileMapnew.hpp"

#define TAILLEBLOC 32

//bool actionDon = false;
bool windowOpen = true;
int id = 1;

// on crée la fenêtre

sf::RenderWindow window(sf::VideoMode(1350, 800), "Tilemap");

void moteurJeu(MAP_Carte& map1, MOTEUR_ListeAction& actions);
//bool collisions(int dx, int dy, int numdir, std::vector<int> level);


int main()
{

	MAP_Carte map1(id, 67, 23);
	MOTEUR_ListeAction actions(&map1);
	RENDU_Fenetre fenetre(&window, &map1);
	
	TileMapnew tilemap;
	tilemap.setMap(&map1);
	
	fenetre.addElementToList(&tilemap);
	
	
	
	//Personnage Principal - map1.getListCharacters()[0] - perso
    //MAP_InventairePersonnage inventairePrincipal=MAP_InventairePersonnage();
	std::string bob = "bob";
	//Race hum = HUMAIN;
	//Profession sold = SOLDAT;
	//Groupe gentil=GENTIL;
	MAP_Personnage persoPrincipal = MAP_Personnage(bob);
	MAP_Personnage* ptrpersoPrincipal = &persoPrincipal;
	persoPrincipal.setX(8*TAILLEBLOC);
	persoPrincipal.setY(8*TAILLEBLOC);
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
	MAP_Personnage* ptrperso2 = &perso2;
	perso2.setX(15*TAILLEBLOC);
	perso2.setY(15*TAILLEBLOC);
	map1.addCharacter(ptrperso2);
	map1.getListCharacters().push_back(ptrperso2);

	RENDU_Sprite sprite2("../res/images/Loup-garou.png", "bobMaman", ptrperso2);
	fenetre.addElementToList(&sprite2);

	while(1){
		fenetre.afficherFenetre();
		moteurJeu(map1,actions);
		
		if(windowOpen==false) break;
	}
    return 0;
}


/*
* commande : 	Z : aller en haut
* 				Q : aller à gauche
* 				S : aller en bas
* 				D : aller à droite
* 				F : fermer la fenetre
*/
void moteurJeu(MAP_Carte& map1, MOTEUR_ListeAction& actions){
	MOTEUR_DeplacementPersonnage action;
	int X1=0;
	int X2=0;
	int Y1=0;
	int Y2=0;
	
	int dx=0;
	int dy=0;
	
	int signe=0;

	//Si le perso principal est en déplacement		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		action=MOTEUR_DeplacementPersonnage(TAILLEBLOC,0,(map1.getListCharacters()[0]));
		actions.addAction(&action);

		// check if action is true

		// la touche "flèche gauche" est enfoncée : on bouge le personnage
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		action=MOTEUR_DeplacementPersonnage(-TAILLEBLOC,0,(map1.getListCharacters()[0]));
		actions.addAction(&action);

		// la touche "flèche gauche" est enfoncée : on bouge le personnage
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		action=MOTEUR_DeplacementPersonnage(0,-TAILLEBLOC,(map1.getListCharacters()[0]));
		actions.addAction(&action);
			
			
	// la touche "flèche gauche" est enfoncée : on bouge le personnage
		//map1.getListCharacters()[0].setY(map1.getListCharacters()[0].getY()-TAILLEBLOC);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		action=MOTEUR_DeplacementPersonnage(0,TAILLEBLOC,(map1.getListCharacters()[0]));
		actions.addAction(&action);

	}else{

	//Si le perso principal ne se déplace plus, le perso2 le rejoint
		// Permet de déplacer le perso2 vers le persoPrincipal
		
		X1=map1.getListCharacters()[0]->getX();
		Y1=map1.getListCharacters()[0]->getY();
		X2=map1.getListCharacters()[1]->getX();
		Y2=map1.getListCharacters()[1]->getY();
		
		if(X1==X2 && Y1==Y2){
			/*action = MOTEUR_DeplacementPersonnage(signe*dx, signe*dy, (map1.getListCharacters()[1]));
			actions.addAction(&action);
			actions.setPermissionTrue(actions.getActionNumber());*/
		}else if((X1-X2)*(X1-X2)<(Y1-Y2)*(Y1-Y2)){
			dy=TAILLEBLOC;
			if(Y1<Y2){
				signe = -1;
			}else{
				signe=1;
			}
			action = MOTEUR_DeplacementPersonnage(signe*dx, signe*dy, (map1.getListCharacters()[1]));
			actions.addAction(&action);
		}else{
			dx=TAILLEBLOC;
			if(X1<X2){
				signe = -1;
			}else{
				signe= 1;
			}
			action = MOTEUR_DeplacementPersonnage(signe*dx, signe*dy, (map1.getListCharacters()[1]));
			actions.addAction(&action);
		}
	}

	actions.apply();

	//quitter la fenetre
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		window.close();
		windowOpen = false;
	}	
	
}
