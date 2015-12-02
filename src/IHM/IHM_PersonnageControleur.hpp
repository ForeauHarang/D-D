#ifndef IHM_PERSONNAGECONTROLEUR_HPP
#define IHM_PERSONNAGECONTROLEUR_HPP

#include <Event.hpp>
#include "../MAP_Personnage.hpp"

// IHM => cré une commande qui sera envoyé au moteur

class IHM_PersonnageControleur {

	private:
		sf::Event event;
		MAP_Personnage perso;

	public:
		IHM_PersonnageControleur();
		~IHM_PersonnageControleur();

	void déplacementCommande(sf::Event event);

};

#endif