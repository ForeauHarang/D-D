#ifndef MAP_CARTE_HPP
#define MAP_CARTE_HPP

#include "MAP_Personnage.hpp"
#include "MAP_VariablesGlobales.hpp"
#include "MAP_Quete.hpp"
#include "MAP_Coffre.hpp"

class MAP_Carte{
	private :
		int idCarte;
		MAP_Personnage* listePersonnages[];
		MAP_Quete* listeQuetes[];
		MAP_Coffre* listeCoffres[];
		int* listeElementsInfranchissables;
		int nombrePersonnages;
		int nombreQuetes;
		int nombreCoffres;
		int nombreElementsInfranchissables;
	
	public :
	
		/*
		 * constructeurs
		 * */
		 
		 MAP_Carte(int idCarte);
		 
		 /*
		  * destructeurs
		  * */
		  
		 ~MAP_Carte();
		
		/*
		 * liste des getteurs
		 * */
		
		MAP_Personnage* getListCharacters();
		MAP_Quete* getListQuests();
		MAP_Coffre* getListChest();
		int* getListImpassableElement();
		
		
		/*
		 * liste des setteurs
		 * */
		 
		void addCharacter(MAP_Personnage);
		void removeCharacter(MAP_Personnage);
		
		void addQuest(MAP_Quete);
		void removeQuest(MAP_Quete);
		
		void addChest(MAP_Coffre);
		void removeChest(MAP_Coffre);
		
		void addImpassableElement(int, int);
		void removeImpassableElement(int, int);
};

#endif
