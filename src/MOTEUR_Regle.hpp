#ifndef MOTEUR_REGLE_HPP
#define MOTEUR_REGLE_HPP

#include "MOTEUR_DeplacementPersonnage.hpp"
#include "MAP_Carte.hpp"

#define TAILLEBLOC 32

class MOTEUR_Regle{
	private:
		MAP_Carte* CARTE_carte;
	public:
	
		/*
		 * Constructeur 
		 */
		
		MOTEUR_Regle();
		
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
