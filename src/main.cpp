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

#define TAILLEBLOC 32

//MOTEUR_DeplacementPersonnage action;
//MOTEUR_ListeAction actions = MOTEUR_ListeAction();

bool actionDon = false;
bool windowOpen = true;
int numdir = 0;
int id = 1;

// on crée la fenêtre
sf::RenderWindow window(sf::VideoMode(1350, 800), "Tilemap");


// on crée la tilemap avec le niveau précédemment défini
TileMap map;


void rendu(MAP_Carte& map1);
void moteurJeu(MAP_Carte& map1, MOTEUR_ListeAction& actions);
//bool collisions(int dx, int dy, int numdir, std::vector<int> level);


int main()
{
	MAP_Carte map1(id);
	MOTEUR_ListeAction actions(&map1);
	//Personnage Principal - map1.getListCharacters()[0] - perso
    MAP_InventairePersonnage inventairePrincipal=MAP_InventairePersonnage();
	std::string bob = "bob";
	Race hum = HUMAIN;
	Profession sold = SOLDAT;
	Groupe gentil=GENTIL;
	MAP_Personnage persoPrincipal = MAP_Personnage(bob);
	MAP_Personnage* ptrpersoPrincipal = &persoPrincipal;
	persoPrincipal.setX(8*TAILLEBLOC);
	persoPrincipal.setY(8*TAILLEBLOC);
	map1.addCharacter(ptrpersoPrincipal);
	map1.getListCharacters().push_back(ptrpersoPrincipal);

	//Personnage 2 - map1.getListCharacters()[1] - perso2
	MAP_InventairePersonnage inventaire2 = MAP_InventairePersonnage();
	std::string bobMaman = "bobMaman";
	Race hum2 = VAMPIRE;
	Profession sold2 = SOLDAT;
	Groupe gentil2 = GENTIL;
	MAP_Personnage perso2 = MAP_Personnage(bobMaman);
	MAP_Personnage* ptrperso2 = &perso2;
	perso2.setX(15*TAILLEBLOC); 
	perso2.setY(15*TAILLEBLOC); 
	map1.addCharacter(ptrperso2);
	map1.getListCharacters().push_back(ptrperso2);

	



	while(1){

		rendu(map1);
		moteurJeu(map1,actions);
		//collisions(TAILLEBLOC, TAILLEBLOC, numdir, level);
		//std::cout << numdir << std::endl;
		
		if(windowOpen==false) break;
	}
    return 0;
}

void rendu(MAP_Carte& map1){
	int x=map1.getListCharacters()[0]->getX();
	int y=map1.getListCharacters()[0]->getY();

	int x2 = map1.getListCharacters()[1]->getX();
	int y2 = map1.getListCharacters()[1]->getY();

  	/* Récupérer l'image pour le personnage principal */
	sf::Texture texturePrincipale;
	texturePrincipale.loadFromFile("../res/images/vampire.png");
	
	/* Créer l'image pour le premier personnage */
	sf::Sprite perso;
	perso.setTexture(texturePrincipale);
	perso.setTextureRect(sf::IntRect(0, TAILLEBLOC, TAILLEBLOC, TAILLEBLOC));

	/* Récupérer l'image pour le deuxième personnage */
	sf::Texture texture2;
	texture2.loadFromFile("../res/images/Loup-garou.png");

	/* Créer l'image pour le deuxième personnage */
	sf::Sprite perso2;
	perso2.setTexture(texture2);
	perso2.setTextureRect(sf::IntRect(0, TAILLEBLOC, TAILLEBLOC, TAILLEBLOC));

	//Chargement de la map
	if (!map.load("../res/images/petiteimages.jpeg", sf::Vector2u(TAILLEBLOC, TAILLEBLOC), map1.getMap(), 67, 23))
		std::cout<<"erreur chargement petiteimages.jpeg\n"<<std::endl;


	
	sf::Event event;
//	while (window.pollEvent(event))
//	{		
		//perso.setPosition(persoPrincipal.getX(),persoPrincipal.getY());
		
		perso.setPosition(x,y);
		perso2.setPosition(x2, y2);
//	}
	    window.clear();
        window.draw(map);
        window.draw(perso);
		window.draw(perso2);
        window.display();
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
		numdir = 1;
		action=MOTEUR_DeplacementPersonnage(TAILLEBLOC,0,(map1.getListCharacters()[0]));
		actions.addAction(&action);

		// check if action is true
		if(map1.getListCharacters()[0]->getX()<41*TAILLEBLOC) // le personnage ne peut pas aller hors de l'ecran; par défaut, permission=false
			actions.setPermissionTrue(actions.getActionNumber());
			//std::cout<<actions.getPermissionFromList(actions.getActionNumber())<<std::endl;
			
		// la touche "flèche gauche" est enfoncée : on bouge le personnage
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		numdir = 2;
		action=MOTEUR_DeplacementPersonnage(-TAILLEBLOC,0,(map1.getListCharacters()[0]));
		actions.addAction(&action);

		// check if action is true
		if(map1.getListCharacters()[0]->getX()>0)
			actions.setPermissionTrue(actions.getActionNumber());			

		// la touche "flèche gauche" est enfoncée : on bouge le personnage
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		numdir = 3;
		action=MOTEUR_DeplacementPersonnage(0,-TAILLEBLOC,(map1.getListCharacters()[0]));
		actions.addAction(&action);

		// check if action is true
		if(map1.getListCharacters()[0]->getY()>0)
			actions.setPermissionTrue(actions.getActionNumber());
			
			
	// la touche "flèche gauche" est enfoncée : on bouge le personnage
		//map1.getListCharacters()[0].setY(map1.getListCharacters()[0].getY()-TAILLEBLOC);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		numdir = 4;
		action=MOTEUR_DeplacementPersonnage(0,TAILLEBLOC,(map1.getListCharacters()[0]));
		actions.addAction(&action);

		// check if action is true
		if(map1.getListCharacters()[0]->getY()<21*TAILLEBLOC)
			actions.setPermissionTrue(actions.getActionNumber());
		else actions.setPermissionFalse(actions.getActionNumber());
					
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
			actions.setPermissionTrue(actions.getActionNumber());
		}else{
			dx=TAILLEBLOC;
			if(X1<X2){
				signe = -1;
			}else{
				signe= 1;
			}
			action = MOTEUR_DeplacementPersonnage(signe*dx, signe*dy, (map1.getListCharacters()[1]));
			actions.addAction(&action);
			actions.setPermissionTrue(actions.getActionNumber());
		}
	}

	actions.apply();

	//quitter la fenetre
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		window.close();
		windowOpen = false;
	}	
	
}


//Collisions
/*
bool collisions(int dx, int dy, int numdir, std::vector<int> level)
{
	int w = map1.getWidthMap();
	int x = dy*w + dx;

	if(numdir == 3) { //vers le haut
		if (level[x - w] > 14) {
			std::cout << "Attention Obstacle" << std::endl;
			return false; //tu ne peux pas passer
		}
	}

	return true; //tu peux passer
}
*/


 /*MAP_Carte carte1 = new MAP_Carte();
 RENDU_Scene scene1 = new RENDU_Scene();
 MAP_Personnage perso1 = new MAP_Personnage("Perso1");
 MAP_Coffre coffre1 = new MAP_Coffre(1,820,550,COUTEAU, ARME);

 carte1.addCharacter(perso1);
 carte1.addChest(coffre1);

 scene1->plan[0].setCarteMap(carte1);*/


 	/*// Découper l'image 
 	carte.setTextureRect(sf::IntRect(0, 277, 847, 616));*/
