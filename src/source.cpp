#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cstdlib>

sf::Window window;

int main() {
	//Cr�ation de la fen�tre 600*800
	window.create(sf::VideoMode(800, 600), "Tuto SFML");
	//Modifier la position
	window.setPosition(sf::Vector2i(192, 0));
	
	//Tant que la fen�tre est ouverte ..
	while (window.isOpen()) {
		sf::Event event;
		//Test des �v�nements
		while (window.pollEvent(event)) {
			//Si on clique sur Fermer
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
	return 0;
}