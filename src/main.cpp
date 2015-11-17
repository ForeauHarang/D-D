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

#define TAILLEBLOC 16

MOTEUR_DeplacementPersonnage action;
bool actionDon = false;

MOTEUR_ListeAction actions=MOTEUR_ListeAction();


//on évite de recharger dans la boucle principale les constantes : permet une fenetre "fluide"
int herbe0=96;
int herbe1=97;
int terre2=100;
int terre3=99;
int route4=162;//180 : eau (en fait, toit bleu)
int route5=120;//115 : eau2
int water6=115;
int water7=115;

// on crée la fenêtre
sf::RenderWindow window(sf::VideoMode(800, 600), "Tilemap");

// on définit le niveau à l'aide de numéro de tuiles
const int level[] =
{
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route4,route4,route4,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre3,water6,water6,water7,water7,water7,water7,water7,water7,water6,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route4,route4,route4,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre3,terre3,water6,water7,water7,water7,water7,water6,water6,water6,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route4,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,water6,water6,water7,water7,water6,water6,terre3,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,water6,herbe0,herbe0,herbe0,herbe0,terre3,route5,terre3,route5,water6,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route4,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,water6,water6,water6,water6,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,route5,route5,route5,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route4,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,terre3,terre3,terre3,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,route5,water6,route5,water6,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,route4,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,route5,route5,route5,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,route4,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,water6,route5,terre3,route5,water6,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,route4,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe1,herbe1,route4,route4,route4,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	herbe1,herbe1,herbe1,route4,route4,route4,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	herbe1,herbe1,herbe1,herbe1,route4,route4,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	herbe0,herbe0,herbe0,herbe0,route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	terre2,terre2,terre2,terre2,route4,route4,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,
	terre3,terre3,terre3,terre3,route4,route4,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,
	route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,
	route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,
	route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,route5,
	route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route5,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,route4,
	terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,route5,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,
	terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,route5,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,terre2,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,route5,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,route5,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,route5,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,herbe1,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,route5,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,terre3,herbe0,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,water6,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,herbe0,herbe0,terre3,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,water6,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,terre3,herbe0,terre3,terre3,terre3,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,route5,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	route4,route4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe1,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe1,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe1,herbe1,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre3,terre3,terre3,terre3,terre3,terre3,terre3,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,terre2,terre2,terre2,terre2,terre3,terre3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,terre2,terre2,terre2,terre2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
	herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,route5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,terre2,terre2,terre2,terre2,terre2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0
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
	persoPrincipal.setX(15*TAILLEBLOC);
	persoPrincipal.setY(15*TAILLEBLOC);
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
	perso2.setX(30 * TAILLEBLOC); 
	perso2.setY(30 * TAILLEBLOC); 
	map1.addCharacter(ptrperso2);
	map1.getListCharacters().push_back(ptrperso2);
	
	std::cout << "(" << map1.getListCharacters()[1]->getX() << "," << map1.getListCharacters()[1]->getY() << ")" << std::endl;
	std::cout << "(" << map1.getListCharacters()[0]->getX() << "," << map1.getListCharacters()[0]->getY() << ")" << std::endl;

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

  	/* Récupérer l'image pour le personnage */
	sf::Texture texture;
	texture.loadFromFile("../res/images/vampire.png");
	
	/* Créer l'image pour le premier personnage */
	sf::Sprite perso;
	perso.setTexture(texture);
	perso.setTextureRect(sf::IntRect(0, 32, 32, 32));	
	if (!map.load("../res/images/petiteimages.jpeg", sf::Vector2u(16, 16), level, 67, 36))
		std::cout<<"erreur chargement petiteimages.jpeg\n"<<std::endl;

	/* Créer l'image pour le deuxième personnage */
	sf::Sprite perso2;
	perso2.setTexture(texture);
	perso2.setTextureRect(sf::IntRect(0, 32, 32, 32));
	
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		action=MOTEUR_DeplacementPersonnage(TAILLEBLOC,0,(map1.getListCharacters()[0]));
		actionDon=true;	
		actions.addAction(&action);

		// check if action is true
		if(map1.getListCharacters()[0]->getX()<48*TAILLEBLOC) // le personnage ne peut pas aller hors de l'ecran; par défaut, permission=false
			actions.setPermissionTrue(actions.getActionNumber());
			//std::cout<<actions.getPermissionFromList(actions.getActionNumber())<<std::endl;
			
		// la touche "flèche gauche" est enfoncée : on bouge le personnage
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		action=MOTEUR_DeplacementPersonnage(-TAILLEBLOC,0,(map1.getListCharacters()[0]));
		actionDon=true;	
		actions.addAction(&action);

		// check if action is true
		if(map1.getListCharacters()[0]->getX()>0)
			actions.setPermissionTrue(actions.getActionNumber());			

		// la touche "flèche gauche" est enfoncée : on bouge le personnage
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		action=MOTEUR_DeplacementPersonnage(0,-TAILLEBLOC,(map1.getListCharacters()[0]));
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
		if(map1.getListCharacters()[0]->getY()<34*TAILLEBLOC)
			actions.setPermissionTrue(actions.getActionNumber());			
			
	}

	if (map1.getListCharacters()[1]->getX() != map1.getListCharacters()[0]->getX()) {
		if (map1.getListCharacters()[1]->getX() < map1.getListCharacters()[0]->getX()) {
			action = MOTEUR_DeplacementPersonnage(TAILLEBLOC, 0, (map1.getListCharacters()[1]));
			std::cout << "vers la droite" << std::endl;
			actions.addAction(&action);
			actions.setPermissionTrue(actions.getActionNumber());
		}
		else {
			action = MOTEUR_DeplacementPersonnage(-TAILLEBLOC, 0, (map1.getListCharacters()[1]));
			std::cout << "vers la gauche" << std::endl;
			actions.addAction(&action);
			actions.setPermissionTrue(actions.getActionNumber());

		}
	}
	else if (map1.getListCharacters()[1]->getY() != map1.getListCharacters()[0]->getY()) {
		if (map1.getListCharacters()[1]->getY() < map1.getListCharacters()[0]->getY()) {
			action = MOTEUR_DeplacementPersonnage(0, TAILLEBLOC, (map1.getListCharacters()[1]));
			std::cout << "vers le bas" << std::endl;
			actions.addAction(&action);
			actions.setPermissionTrue(actions.getActionNumber());
		}
		else {
			action = MOTEUR_DeplacementPersonnage(0, -TAILLEBLOC, (map1.getListCharacters()[1]));
			std::cout << "vers le haut" << std::endl;
			actions.addAction(&action);
			actions.setPermissionTrue(actions.getActionNumber());
		}
	}
		
	actions.apply();
		
	//commandCheck; if istrue => send engine; else delete 
	// engine : exec commande
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){ //quitter la fenetre
		window.close();
		windowOpen=false;
	}
	
}








/*
 * commande : 	Z : aller en haut
 * 				Q : aller à gauche
 * 				S : aller en bas
 * 				D : aller à droite
 * 				F : fermer la fenetre
 */

 //using namespace sf;
 /*
 int main()
 {
 std::cout << "Hello World!" << std::endl;
 /*
 *  void initCarte();
 */
 /*
 MAP_Carte *TestCarte = new MAP_Carte(1);
 }
 */

 //int main(int argc, char* argv[]) {
 ////	cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << endl;
 //	sf::RenderWindow screen(sf::VideoMode(800, 600), "W&V");


 /*MAP_Carte carte1 = new MAP_Carte();
 RENDU_Scene scene1 = new RENDU_Scene();
 MAP_Personnage perso1 = new MAP_Personnage("Perso1");
 MAP_Coffre coffre1 = new MAP_Coffre(1,820,550,COUTEAU, ARME);

 carte1.addCharacter(perso1);
 carte1.addChest(coffre1);

 scene1->plan[0].setCarteMap(carte1);*/

 //	/* Récupérer l'image */
 //	sf::Texture texture;
 //	texture.loadFromFile("../res/images/IMAGE.jpg");
 //	
 //	/* Créer une partie de l'image */
 //	sf::Sprite carte;
 //	carte.setTexture(texture);

 //	/* Découper l'image */
 //	carte.setTextureRect(sf::IntRect(0, 277, 847, 616));

 //		bool running = true;
 //		while (running) {
 //		screen.draw(carte);
 //		screen.display();
 //		
 //		
 //		
 //		screen.clear();
 //	}	

 //sf::Window screen(sf::VideoMode(800, 600), "myproject");



 //	return 67;
 //}
