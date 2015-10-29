#include <iostream>
#include "MAP_Carte.hpp"
#include "FIGHT_Carte.hpp"
#include <SFML/Graphics.hpp>
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
		
int main(int argc, char* argv[]) {
//	cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << endl;

	/*MAP_Carte carte1 = new MAP_Carte();
	RENDU_Scene scene1 = new RENDU_Scene();
	MAP_Personnage perso1 = new MAP_Personnage("Perso1");
	MAP_Coffre coffre1 = new MAP_Coffre(1,820,550,COUTEAU, ARME);
	
	carte1.addCharacter(perso1);
	carte1.addChest(coffre1);
	
	scene1->plan[0].setCarteMap(carte1);*/
	
	/* Récupérer l'image */
	sf::Image image;
	Image.LoadFromFile("IMAGE.jpeg");
	
	/* Créer une partie de l'image */
	sf::Sprite carte;
	carte.setImage(image);
	
	/* Découper l'image */
	carte.SetSubRect(sf::IntRect(0, 277, 847, 616));

	sf::Window screen(sf::VideoMode(800, 600), "myproject");
	bool running = true;
	while (running) {
		//screen.Display();
	}	 
		 
	return 67;
}
