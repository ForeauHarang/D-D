#include <iostream>
#include "MAP_Carte.hpp"
#include "FIGHT_Carte.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "TileMap.hpp"
#include "MAP_Personnage.hpp"
#include "MAP_VariablesGlobales.hpp"

#define TAILLEBLOC 16

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

bool windowOpen=true;

int main()
{
	

    MAP_InventairePersonnage inventairePrincipal=MAP_InventairePersonnage();
	std::string bob = "bob";
	Race hum = HUMAIN;
	Profession sold = SOLDAT;
	Groupe gentil=GENTIL;
	MAP_Personnage persoPrincipal=MAP_Personnage(bob);//hum, sold, gentil, inventairePrincipal, bob);
	MAP_Personnage* ptrpersoPrincipal = &persoPrincipal;
	persoPrincipal.setX(15*TAILLEBLOC);
	persoPrincipal.setY(15*TAILLEBLOC);
	map1.addCharacter(ptrpersoPrincipal);
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
//    while (window.isOpen())
//    {
        // on gère les évènements
       
        //perso.setPosition(300,250);
		rendu();//map1);
 //   }
		moteurJeu();
		if(windowOpen==false) break;
	}
    return 0;
}

void rendu(){//MAP_Carte map1){
	int x=map1.getListCharacters()[0].getX();
	int y=map1.getListCharacters()[0].getY();
    //MAP_Personnage persoPrincipal=map1.getListCharacters()[0];
    //	/* Récupérer l'image */
	sf::Texture texture;
	texture.loadFromFile("../res/images/IMAGE.jpg");
	
//	/* Créer une partie de l'image */
	sf::Sprite perso;
	perso.setTexture(texture);
	perso.setTextureRect(sf::IntRect(0, 32, 32, 32));	
		if (!map.load("../res/images/petiteimages.jpeg", sf::Vector2u(16, 16), level, 67, 36))
	std::cout<<"erreur chargement petiteimages.jpeg\n"<<std::endl;
	
	
	sf::Event event;
//	while (window.pollEvent(event))
//	{
		
		//perso.setPosition(persoPrincipal.getX(),persoPrincipal.getY());
		
		
		perso.setPosition(x,y);
//	}
	    window.clear();
        window.draw(map);
        window.draw(perso);
        window.display();
}

void moteurJeu(){

	
	bool ordre=true;
	if(ordre){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		
    // la touche "flèche gauche" est enfoncée : on bouge le personnage
			map1.getListCharacters()[0].setX(map1.getListCharacters()[0].getX()+TAILLEBLOC);
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		
    // la touche "flèche gauche" est enfoncée : on bouge le personnage
			map1.getListCharacters()[0].setX(map1.getListCharacters()[0].getX()-TAILLEBLOC);
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
		
    // la touche "flèche gauche" est enfoncée : on bouge le personnage
			map1.getListCharacters()[0].setY(map1.getListCharacters()[0].getY()-TAILLEBLOC);
		}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		
    // la touche "flèche gauche" est enfoncée : on bouge le personnage
			map1.getListCharacters()[0].setY(map1.getListCharacters()[0].getY()+TAILLEBLOC);
		}
	//	map1.getListCharacters()[0].setX(map1.getListCharacters()[0].getX()+1);
		
		if(map1.getListCharacters()[0].getX()>48*TAILLEBLOC) map1.getListCharacters()[0].setX(48*TAILLEBLOC);// le personnage ne peut pas aller hors de l'ecran //commandetemp = commande(deplacement, droite,persoPrincipal), addCommand(commandetemp)
		if(map1.getListCharacters()[0].getX()<0) map1.getListCharacters()[0].setX(0); // le personnage ne peut pas aller hors de l'ecran
		if(map1.getListCharacters()[0].getY()<0) map1.getListCharacters()[0].setY(0); // le personnage ne peut pas aller hors de l'ecran
		if(map1.getListCharacters()[0].getY()>34*TAILLEBLOC) map1.getListCharacters()[0].setY(34*TAILLEBLOC); // le personnage ne peut pas aller hors de l'ecran
		
		// 				//commandCheck; if istrue => send engine; else delete // engine : exec commande
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){ //quitter la fenetre
			window.close();
			windowOpen=false;
		}
		
	}
	
}


/*
 * commande : 	Z : aller en haut
 * 				Q : aller à gauche
 * 				S : aller en bas
 * 				D : aller à droite
 * 				F : fermer la fenetre
 */
