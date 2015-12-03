#ifndef IA_IASIMPLE_HPP
#define IA_IASIMPLE_HPP

#include "../MOTEUR/MOTEUR_DeplacementPersonnage.hpp"
#include "../MOTEUR/MOTEUR_ListeAction.hpp"
#include "../MAP/MAP_Carte.hpp"

class IA_IASimple {
	private :
		MOTEUR_ListeAction* actions;
		MAP_Carte* map;

	public :
		/*
		* Constructeur
		*/
		IA_IASimple::IA_IASimple(MAP_Carte* map, MOTEUR_ListeAction* actions);

		/*
		* Destructeur
		*/
		IA_IASimple::~IA_IASimple();

		/*
		* Méthodes
		*/
		void IA_IASimple::reachTarget(MAP_Carte* map, int X1, int Y1, int X2, int Y2);
};

#endif
