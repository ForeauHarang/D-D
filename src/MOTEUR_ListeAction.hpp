#ifndef MOTEUR_LISTEACTION_HPP
#define MOTEUR_LISTEACTION_HPP

#include "MOTEUR_Action.hpp"
#include <iostream>

#define LISTEMAX 1024



class MOTEUR_ListeAction{
	private:
		MOTEUR_Action *listeAction[LISTEMAX];
		bool permission[LISTEMAX];
		int nombreAction;
	
	public:
		/*
		 * Constructeur 
		 */
		 
		MOTEUR_ListeAction();
		
		/*
		 * Destructeur 
		 */
		
		~MOTEUR_ListeAction();
		
		/*
		 * Getters
		 */
		 
		MOTEUR_Action* getActionFromList(int placeDansListe);
		int getActionNumber();
		bool getPermissionFromList(int pladeDansListe);
		
		/*
		 * Setters
		 */
		
		void addAction(MOTEUR_Action *action);
		void setPermissionTrue(int placeDansListe);
		void setPermissionFalse(int placeDansListe);		
		void removeAction(int placeDansListe);
		/*
		 * Methodes
		 */ 
		
		void apply();
		
};

#endif
