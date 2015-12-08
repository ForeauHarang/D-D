#ifndef MOTEUR_LISTEACTION_HPP
#define MOTEUR_LISTEACTION_HPP

#include "MOTEUR_Action.hpp"
#include <iostream>
#include "MOTEUR_Regle.hpp"
#include "MOTEUR_DeplacementPersonnage.hpp"
#include "MOTEUR_QuitterProgramme.hpp"
#include <string>
#include "../MAP/MAP_Carte.hpp"
using std::string;

#define LISTEMAX 1024



class MOTEUR_ListeAction{
	private:
		MOTEUR_Action *listeAction[LISTEMAX];
		int nombreAction;
		MOTEUR_Regle regles;
		bool resterDansLaBoucle=true;

	public:
		/*
		 * Constructeur 
		 */
		MOTEUR_ListeAction();
		MOTEUR_ListeAction(MAP_Carte *carte);
		
		/*
		 * Destructeur 
		 */
		
		~MOTEUR_ListeAction();
		
		/*
		 * Getters
		 */
		 
		MOTEUR_Action* getActionFromList(int placeDansListe);
		int getActionNumber();
		
		/*
		 * Setters
		 */
		
		void addAction(MOTEUR_Action *action);
		void removeAction(int placeDansListe);
		/*
		 * Methodes
		 */ 
		
		void apply();
		
};

#endif
