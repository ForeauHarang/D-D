#include <iostream>
#include "MAP_Carte.hpp"
#include "FIGHT_Carte.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "TileMap.hpp"
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
	int herbe0=96;
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tilemap");
    // on définit le niveau à l'aide de numéro de tuiles
    const int level[] =
    {
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,3,6,6,7,7,7,7,7,7,6,3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,6,7,7,7,7,6,6,6,3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,4,4,4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,3,6,6,7,7,6,6,3,3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,6,herbe0,herbe0,herbe0,herbe0,3,5,3,5,6,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,4,4,4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,3,6,6,6,6,3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,5,5,5,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,4,4,4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,3,3,3,3,3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,3,5,6,5,6,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,herbe0,4,4,4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,5,5,5,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,4,4,4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,6,5,3,5,6,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,4,4,4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		1,1,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		herbe0,herbe0,herbe0,herbe0,4,4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		2,2,2,2,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
		4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
		3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,5,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		4,4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,3,3,herbe0,3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,6,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		4,4,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,3,herbe0,herbe0,3,3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,6,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		4,4,herbe0,herbe0,herbe0,herbe0,herbe0,1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,3,3,herbe0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		4,4,herbe0,herbe0,herbe0,herbe0,herbe0,1,1,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,1,1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,1,1,1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,3,3,3,3,3,3,3,3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,1,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,2,2,2,2,2,3,3,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,2,2,2,2,2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,
		herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,5,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,2,2,2,2,2,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0,herbe0
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load("../res/images/petiteimages.jpeg", sf::Vector2u(16, 16), level, 67, 36))
        return -1;

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}
