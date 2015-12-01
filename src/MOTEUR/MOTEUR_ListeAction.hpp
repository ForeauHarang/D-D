#ifndef MOTEUR_LISTEACTION_HPP
#define MOTEUR_LISTEACTION_HPP

#include "MOTEUR_Action.hpp"
#include <iostream>
#include "MOTEUR_Regle.hpp"
#include "MOTEUR_DeplacementPersonnage.hpp"
#include <string>
#include "../MAP/MAP_Carte.hpp"
using std::string;

#define LISTEMAX 1024



class MOTEUR_ListeAction{
	private:
		MOTEUR_Action *listeAction[LISTEMAX];
		bool permission[LISTEMAX];//a supprimer
		int nombreAction;
		MOTEUR_Regle regles;

	public:
		/*
		 * Constructeur 
		 */
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
		bool getPermissionFromList(int pladeDansListe); // a supprimer
		
		/*
		 * Setters
		 */
		
		void addAction(MOTEUR_Action *action);
		void setPermissionTrue(int placeDansListe);//a supprimer
		void setPermissionFalse(int placeDansListe);//a supprimer		
		void removeAction(int placeDansListe);
		/*
		 * Methodes
		 */ 
		
		void apply();
		
};

#endif
