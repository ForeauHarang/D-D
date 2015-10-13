#ifndef MAP_COFFRE_HPP
#define MAP_COFFRE_HPP


#include "MAP_VariablesGlobales.hpp"
#include "MAP_Personnage.hpp"
//#include "MAP_Carte.hpp"

/* changer l'uml état MAP*/

class MAP_Coffre{
	private :
		int idCoffre; // nom du coffre + coordonnées : exemple : idCoffre=12345678; x = 12345678/10000 = 1234; y = 12345678%10000=5678
		NomObjet nomObjet;
		TypeObjet typeObjet;
		
	public :
				
		/*
		* constructeurs
		* */
		
		MAP_Coffre(int, NomObjet, TypeObjet);
		
		/*
		* destructeurs
		* */
		
		~MAP_Coffre();
		
		/*
		* getteurs
		* */
		
		NomObjet getNameItem();
		TypeObjet getTypeItem();
		int getChestId();
		
		/*
		* setteurs
		* */
		
		/*
		* autres méthodes
		* */
		
		void transfert(MAP_Personnage);
		
};

#endif

