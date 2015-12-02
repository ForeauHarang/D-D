#ifndef IHM_PERSONNAGECONTROLEUR_HPP
#define IHM_PERSONNAGECONTROLEUR_HPP

#include <Event.hpp>
#include "../MAP_Personnage.hpp"

// IHM => cr� une commande qui sera envoy� au moteur

class IHM_PersonnageControleur {

	private:
		sf::Event event;
		MAP_Personnage perso;

	public:
		IHM_PersonnageControleur();
		~IHM_PersonnageControleur();

	void d�placementCommande(sf::Event event);

};

#endif