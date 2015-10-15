#ifndef MAP_PERSONNAGE_HPP
#define MAP_PERSONNAGE_HPP

#include "MAP_VariablesGlobales.hpp"
#include "MAP_InventairePersonnage.hpp"
//#include "MAP_Carte.hpp"

/* changer l'uml état MAP*/

class MAP_Personnage{
	private :
		int* caracteristiques; // cf fin du header
		Race race;
		Profession profession;
		Groupe groupe;
		MAP_InventairePersonnage inventaire;	
		std::string idPersonnage;
		
	public :
			
			/*
			 * constructeurs
			 * */
			 
			MAP_Personnage(int[NOMBRECARAC], Race, Profession, Groupe, MAP_InventairePersonnage, string);
			MAP_Personnage(Race, Profession, Groupe, MAP_InventairePersonnage, string);
			MAP_Personnage(string);
			 
			/*
			 * destructeurs
			 * */
			  
			~MAP_Personnage();
			
			/*
			 * getteurs
			 * */
		
			int* getCharacteristics();
			Race getRace();
			Profession getJob();
			Groupe getGroup();
			string getCharacterId();
			MAP_InventairePersonnage getInventory();
			
			/*
			 * setteurs
			 * */
			 
			void set1characteristicto(int numeroCarac, int nouvelleValeur);
			
			/*
			 * autres méthodes
			 * */
			void openInventory();
			void closeInventory();
	
};

#endif

/*
caractéristiques :
  	carac[0] : force
	carac[1] : dexterite
	carac[2] : intelligence
	carac[3] : experience
	carac[4] : niveau
	carac[5] : point de vie
	carac[6] : sprite
	carac[7] : coordonnée x
	carac[8] : coordonnée y
*/
