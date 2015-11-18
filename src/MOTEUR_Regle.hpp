#ifndef MOTEUR_REGLE_HPP
#define MOTEUR_REGLE_HPP

#include "MOTEUR_DeplacementPersonnage.hpp"

class MOTEUR_Regle{
	private:
		MAP_Carte* CARTE_carte;
		MOTEUR_ListeAction *actions;
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
		void setActionList(MOTEUR_ListeAction*);
		/*
		 * Methodes
		 */  
		bool isAvailable(MOTEUR_DeplacementPersonnage);
};

#endif
