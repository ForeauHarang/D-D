#ifndef MAP_CARTE_HPP
#define MAP_CARTE_HPP

#include "MAP_VariablesGlobales.hpp"
#include "MAP_Personnage.hpp"
#include "MAP_Quete.hpp"
#include "MAP_Coffre.hpp"

class MAP_Carte{
	private :
		int idCarte;
		//MAP_Personnage* listePersonnages[NBPERSO];
		std::vector<MAP_Personnage*> listePersonnages;
		MAP_Quete* listeQuetes[NBQUETES];
		MAP_Coffre* listeCoffres[NBCOFFRES];
		int* listeElementsInfranchissables;
		int nombrePersonnages;
		int nombreQuetes;
		int nombreCoffres;
		int nombreElementsInfranchissables;
		int height = 23;
		int width = 67;
	
	public :		
		// on définit le niveau à l'aide de numéro de tuiles
		std::vector<int> level;
		

		/*
		 * constructeurs
		 * */	 
		 MAP_Carte(int idCarte);
		 MAP_Carte();

		 /*
		  * destructeurs
		  * */
		 ~MAP_Carte();
		
		/*
		 * liste des getteurs
		 * */
		std::vector<MAP_Personnage*> getListCharacters();
		MAP_Quete* getListQuests();
		MAP_Coffre* getListChest();
		int* getListImpassableElement();
		std::vector<int> getMap();
		int getWidthMap();
		int getHeightMap();
		
		
		/*
		 * liste des setteurs
		 * */
		void addCharacter(MAP_Personnage*);
		void removeCharacter(MAP_Personnage);
		
		void addQuest(MAP_Quete);
		void removeQuest(MAP_Quete);
		
		void addChest(MAP_Coffre);
		void removeChest(MAP_Coffre);
		
		void addImpassableElement(int, int);
		void removeImpassableElement(int, int);
};

#endif
