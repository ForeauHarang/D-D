#include <iostream>
#include "MAP_Carte.hpp"
#include "FIGHT_Carte.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "TileMap.hpp"
#include "MAP_Personnage.hpp"
#include "MAP_VariablesGlobales.hpp"
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

int main()
{
	

    MAP_InventairePersonnage inventairePrincipal=MAP_InventairePersonnage();
	std::string bob = "bob";
	Race hum = HUMAIN;
	Profession sold = SOLDAT;
	Groupe gentil=GENTIL;
	MAP_Personnage persoPrincipal=MAP_Personnage(bob);//hum, sold, gentil, inventairePrincipal, bob);
	MAP_Personnage* ptrpersoPrincipal = &persoPrincipal;
	persoPrincipal.setX(300);
	std::cout<<persoPrincipal.getX()<<std::endl;
	//std::cout<<persoPrincipal->getX()<<std::endl;
	persoPrincipal.setY(250);
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
		persoPrincipal.setX(persoPrincipal.getX()+1);
		
		if(persoPrincipal.getX()>60) persoPrincipal.setX(20); // le personnage bouge
		rendu();//map1);
 //   }
	
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
	
	
//	sf::Event event;
//	while (window.pollEvent(event))
//	{
//		if(event.type == sf::Event::Closed)
//			window.close();
		
		//perso.setPosition(persoPrincipal.getX(),persoPrincipal.getY());
		perso.setPosition(x,y);
//	}
	    window.clear();
        window.draw(map);
        window.draw(perso);
        window.display();
}

void moteurJeu(){
	if(1){
		
	}
	
}
