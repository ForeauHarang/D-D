#ifndef RENDU_FENETRE_HPP
#define RENDU_FENETRE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

#include "RENDU_ElementGraphique.hpp"
#include "../MAP/MAP_Carte.hpp"
#include "TileMapnew.hpp"
#include "RENDU_Sprite.hpp"

#define TAILLEBLOC 32

class RENDU_Fenetre {
	private:
		sf::RenderWindow* window;
		std::vector<RENDU_ElementGraphique*> listeElementGraphique;
		MAP_Carte* map1;

	public:
		/*
		* constructeurs
		* */
		RENDU_Fenetre(sf::RenderWindow* window, MAP_Carte* map1);

		/*
		* Destructeurs
		* */
		~RENDU_Fenetre();

		/*
		* M�thodes
		* */
		void afficherElementGraphique();
		void afficherFenetre();
		void addElementToList(RENDU_ElementGraphique* element);
		//void removeElementFromList(std::string name);

};
#endif
