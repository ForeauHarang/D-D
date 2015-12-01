#ifndef MOTEUR_REGLE_HPP
#define MOTEUR_REGLE_HPP

#include "MOTEUR_DeplacementPersonnage.hpp"
#include "../MAP/MAP_Carte.hpp"
#include <iostream>

#define TAILLEBLOC 32

class MOTEUR_Regle{
	private:
		MAP_Carte* CARTE_carte;
	public:
	
		/*
		 * Constructeur 
		 */		
		MOTEUR_Regle();
		MOTEUR_Regle(MAP_Carte *carte);
		
		/*
		 * Destructeur 
		 */
		 
		~MOTEUR_Regle();
		
		/*
		 * Getters
		 */		
		
		MAP_Carte* getCARTE_Map();
		
		/*
		 * Setters
		 */
		
		void setCARTE_Map(MAP_Carte*);
		/*
		 * Methodes
		 */  
		bool isAvailable(MOTEUR_DeplacementPersonnage *);
		//bool isAvailable(MOTEUR_Action commande);
};

#endif
