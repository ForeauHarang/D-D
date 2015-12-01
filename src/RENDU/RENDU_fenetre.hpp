#ifndef RENDU_fenetre_HPP
#define RENDU_fenetre_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>

//#include "RENDU_ElementGraphique.hpp"
#include "../MAP/MAP_Carte.hpp"
#include "TileMap.hpp"

#define TAILLEBLOC 32

class RENDU_fenetre {
	private:
		sf::RenderWindow* window;
		std::vector<RENDU_ElementGraphique>* listeElementGraphique;
		MAP_Carte* map1;

	public:
		/*
		* constructeurs
		* */
		RENDU_fenetre(sf::RenderWindow* window);

		/*
		* Destructeurs
		* */
		~RENDU_fenetre();

		/*
		* Méthodes
		* */
		void afficherElementGraphique();
		void afficherFenetre();

};
#endif;