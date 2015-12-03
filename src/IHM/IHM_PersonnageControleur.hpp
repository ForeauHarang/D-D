#ifndef IHM_PERSONNAGECONTROLEUR_HPP
#define IHM_PERSONNAGECONTROLEUR_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../MAP/MAP_Carte.hpp"
#include "../MAP/MAP_Personnage.hpp"
#include "../MOTEUR/MOTEUR_ListeAction.hpp"
#include "../MOTEUR/MOTEUR_DeplacementPersonnage.hpp"

// IHM => cré une commande qui sera envoyé au moteur

class IHM_PersonnageControleur {

	private:
		sf::Event event;
		//MAP_Personnage perso;
		MOTEUR_ListeAction actions;
		MAP_Carte* map;

	public:
		IHM_PersonnageControleur(MAP_Carte* map);
		~IHM_PersonnageControleur();

	void deplacementCommande(sf::Event event);
	void fermerFenetre(sf::Event event, sf::RenderWindow* window);

};

#endif