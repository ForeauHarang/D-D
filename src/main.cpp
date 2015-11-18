#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "FIGHT_Carte.hpp"

#include "TileMap.hpp"

#include "MAP_Carte.hpp"
#include "MAP_Personnage.hpp"
#include "MAP_VariablesGlobales.hpp"

#include "MOTEUR_DeplacementPersonnage.hpp"
#include "MOTEUR_ListeAction.hpp"

#define TAILLEBLOC 32

MOTEUR_DeplacementPersonnage action;
bool actionDon = false;

MOTEUR_ListeAction actions=MOTEUR_ListeAction();

	
//on évite de recharger dans la boucle principale les constantes : permet une fenetre "fluide"
int herbe0=9;
int herbe1=54;//Arbres
int terre2=12;
int terre3=14;
int route4=0;//180 : eau (en fait, toit bleu)
int route5=2;//115 : eau2
int water6=15;
int water7=17;

// on crée la fenêtre
sf::RenderWindow window(sf::VideoMode(1350, 800), "Tilemap");

// on définit le niveau à l'aide de numéro de tuiles
const int level[] =
{
	herbe0,herbe0,herbe0,herbe0,route4,route4,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre3,water6,water6,water7,water7,water7,water7,water7,water6,water6,terre3,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,route4,route4,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre3,terre3,water6,water6,water7,water7,water7,water6,water6,terre3,terre3,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe1,terre3,terre3,water6,water6,water6,water6,water6,terre3,terre3,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,water6,herbe0,herbe0,herbe0,herbe0,terre3,route5,terre3,route5,water6,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe1,herbe1,terre3,terre3,terre3,terre3,terre3,herbe1,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,route5,route5,route5,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	//herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route4,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,terre3,terre3,terre3,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,route5,water6,route5,water6,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	//herbe0,herbe0,herbe0,herbe0,herbe0,route4,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,route5,route5,route5,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	//herbe0,herbe0,herbe0,herbe0,route4,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,water6,route5,terre3,route5,water6,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	//herbe0,herbe0,herbe0,route4,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	//herbe1,herbe1,route4,route4,route4,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	//herbe1,herbe1,herbe1,route4,route4,route4,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	//herbe1,herbe1,herbe1,herbe1,route4,route4,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	herbe0,herbe0,herbe0,herbe0,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	terre3,terre3,terre3,terre3,route4,route4,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,
	route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,
	route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,
	route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,
	route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route5,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,
	terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,route5,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,terre2,terre2,terre2,terre2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	//herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,route5,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	//herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,route5,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	//herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,route5,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,route5,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,water6,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,terre2,terre2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe1,herbe1,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,water6,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,terre2,terre2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,route5,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,terre2,terre2,terre2,terre2,terre3,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	//herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	//herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,terre2,terre2,terre2,terre2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	//herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,terre2,terre2,terre2,terre2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0
};
	
// on crée la tilemap avec le niveau précédemment défini
TileMap map;

int id=1;
MAP_Carte map1 = MAP_Carte(id);

void rendu();//MAP_Carte map1);
void moteurJeu();

bool windowOpen=true;

int main()
{
	//Personnage Principal - map1.getListCharacters()[0] - perso
    MAP_InventairePersonnage inventairePrincipal=MAP_InventairePersonnage();
	std::string bob = "bob";
	Race hum = HUMAIN;
	Profession sold = SOLDAT;
	Groupe gentil=GENTIL;
	MAP_Personnage persoPrincipal = MAP_Personnage(bob);
	MAP_Personnage* ptrpersoPrincipal = &persoPrincipal;
	persoPrincipal.setX(5*TAILLEBLOC);
	persoPrincipal.setY(5*TAILLEBLOC);
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
	perso2.setX(15 * TAILLEBLOC); 
	perso2.setY(15 * TAILLEBLOC); 
	map1.addCharacter(ptrperso2);
	map1.getListCharacters().push_back(ptrperso2);
	
	/*
	MAP_Carte carte1 = new MAP_Carte();
	RENDU_Scene scene1 = new RENDU_Scene();
	MAP_Personnage perso1 = new MAP_Personnage("Perso1");
	MAP_Coffre coffre1 = new MAP_Coffre(1,820,550,COUTEAU, ARME);
	carte1.addCharacter(perso1);
	carte1.addChest(coffre1);
	scene1->plan[0].setCarteMap(carte1);*/

	while(1){
	
    // on fait tourner la boucle principale
	//	while (window.isOpen())
    //{
        // on gère les évènements       
        //perso.setPosition(300,250);		
    //}
		rendu();
		moteurJeu();
		
		if(windowOpen==false) break;
	}
    return 0;
}

void rendu(){
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

	//Chagement de la map
	if (!map.load("../res/images/petiteimages.jpeg", sf::Vector2u(TAILLEBLOC, TAILLEBLOC), level, 67, 23))
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


void moteurJeu(){
	int X1=0;
	int X2=0;
	int Y1=0;
	int Y2=0;
	
	int dx=0;
	int dy=0;
	
	int signe=0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		action=MOTEUR_DeplacementPersonnage(TAILLEBLOC / 2,0,(map1.getListCharacters()[0]));
		actionDon=true;	
		actions.addAction(&action);

		// check if action is true
		if(map1.getListCharacters()[0]->getX()<41*TAILLEBLOC) // le personnage ne peut pas aller hors de l'ecran; par défaut, permission=false
			actions.setPermissionTrue(actions.getActionNumber());
			//std::cout<<actions.getPermissionFromList(actions.getActionNumber())<<std::endl;
			
		// la touche "flèche gauche" est enfoncée : on bouge le personnage
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		action=MOTEUR_DeplacementPersonnage(-TAILLEBLOC / 2,0,(map1.getListCharacters()[0]));
		actionDon=true;	
		actions.addAction(&action);

		// check if action is true
		if(map1.getListCharacters()[0]->getX()>0)
			actions.setPermissionTrue(actions.getActionNumber());			

		// la touche "flèche gauche" est enfoncée : on bouge le personnage
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		action=MOTEUR_DeplacementPersonnage(0,-TAILLEBLOC / 2,(map1.getListCharacters()[0]));
		actionDon=true;			
		actions.addAction(&action);

		// check if action is true
		if(map1.getListCharacters()[0]->getY()>0)
			actions.setPermissionTrue(actions.getActionNumber());
			
			
	// la touche "flèche gauche" est enfoncée : on bouge le personnage
		//map1.getListCharacters()[0].setY(map1.getListCharacters()[0].getY()-TAILLEBLOC);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		action=MOTEUR_DeplacementPersonnage(0,TAILLEBLOC,(map1.getListCharacters()[0]));
		actionDon=true;					
		actions.addAction(&action);

		// check if action is true
		if(map1.getListCharacters()[0]->getY()<21*TAILLEBLOC)
			actions.setPermissionTrue(actions.getActionNumber());
		else actions.setPermissionFalse(actions.getActionNumber());
					
	}else{
		

		/*
		* commande : 	Z : aller en haut
		* 				Q : aller à gauche
		* 				S : aller en bas
		* 				D : aller à droite
		* 				F : fermer la fenetre
		*/
		// Permet de déplacer le perso2 vers le persoPrincipal
		
		X1=map1.getListCharacters()[0]->getX();
		Y1=map1.getListCharacters()[0]->getY();
		X2=map1.getListCharacters()[1]->getX();
		Y2=map1.getListCharacters()[1]->getY();
		
		if(X1==X2 && Y1==Y2){
			action = MOTEUR_DeplacementPersonnage(signe*dx, signe*dy, (map1.getListCharacters()[1]));
			actions.addAction(&action);
			actions.setPermissionTrue(actions.getActionNumber());
		}else if((X1-X2)*(X1-X2)<(Y1-Y2)*(Y1-Y2)){
			dy=8;
			if(Y1<Y2){
				signe = -1;
			}else{
				signe=1;
			}
			
			action = MOTEUR_DeplacementPersonnage(signe*dx, signe*dy, (map1.getListCharacters()[1]));
			actions.addAction(&action);
			actions.setPermissionTrue(actions.getActionNumber());
		}else{
			dx=8;
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
	
/*	if(map1.getListCharacters()[1]->getX() == map1.getListCharacters()[0]->getX() && map1.getListCharacters()[1]->getY() == map1.getListCharacters()[0]->getY()){}
	else{
		if (map1.getListCharacters()[1]->getX() != map1.getListCharacters()[0]->getX()) {
			if (map1.getListCharacters()[1]->getX() < map1.getListCharacters()[0]->getX()) {
				if(map1.getListCharacters()[1]->getX() - map1.getListCharacters()[0]->getX() > -16){
					action = MOTEUR_DeplacementPersonnage(map1.getListCharacters()[0]->getX()-map1.getListCharacters()[1]->getX(), 0, (map1.getListCharacters()[1]));
					//std::cout << "vers la droite" << std::endl;
					actions.addAction(&action);
					actions.setPermissionTrue(actions.getActionNumber());
				}else{
					action = MOTEUR_DeplacementPersonnage(TAILLEBLOC/2, 0, (map1.getListCharacters()[1]));
					//std::cout << "vers la droite" << std::endl;
					actions.addAction(&action);
					actions.setPermissionTrue(actions.getActionNumber());
				}
			}
			else {
				if(map1.getListCharacters()[1]->getX() - map1.getListCharacters()[0]->getX() <16){
					action = MOTEUR_DeplacementPersonnage((map1.getListCharacters()[0]->getX()-map1.getListCharacters()[1]->getX()), 0, (map1.getListCharacters()[1]));
					//std::cout << "vers la gauche" << std::endl;
					actions.addAction(&action);
					actions.setPermissionTrue(actions.getActionNumber());
				}else{
					action = MOTEUR_DeplacementPersonnage(-TAILLEBLOC/2, 0, (map1.getListCharacters()[1]));
					//std::cout << "vers la gauche" << std::endl;
					actions.addAction(&action);
					actions.setPermissionTrue(actions.getActionNumber());
				}

			}
		}
		else if (map1.getListCharacters()[1]->getY() != map1.getListCharacters()[0]->getY()) {
			if (map1.getListCharacters()[1]->getY() < map1.getListCharacters()[0]->getY()) {
				action = MOTEUR_DeplacementPersonnage(0, TAILLEBLOC/2, (map1.getListCharacters()[1]));
				//std::cout << "vers le bas" << std::endl;
				actions.addAction(&action);
				actions.setPermissionTrue(actions.getActionNumber());
			}
			else {
				action = MOTEUR_DeplacementPersonnage(0, -TAILLEBLOC/2, (map1.getListCharacters()[1]));
				//std::cout << "vers le haut" << std::endl;
				actions.addAction(&action);
				actions.setPermissionTrue(actions.getActionNumber());
			}
		}
	}
	*/
	


	
		
	actions.apply();
		
	//quitter la fenetre
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){ 
		window.close();
		windowOpen=false;
	}
	
}



 /*MAP_Carte carte1 = new MAP_Carte();
 RENDU_Scene scene1 = new RENDU_Scene();
 MAP_Personnage perso1 = new MAP_Personnage("Perso1");
 MAP_Coffre coffre1 = new MAP_Coffre(1,820,550,COUTEAU, ARME);

 carte1.addCharacter(perso1);
 carte1.addChest(coffre1);

 scene1->plan[0].setCarteMap(carte1);*/


 	/*// Découper l'image 
 	carte.setTextureRect(sf::IntRect(0, 277, 847, 616));*/
