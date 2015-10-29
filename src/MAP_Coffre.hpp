#ifndef MAP_COFFRE_HPP
#define MAP_COFFRE_HPP


#include "MAP_VariablesGlobales.hpp"
#include "MAP_Personnage.hpp"
//#include "MAP_Carte.hpp"

/* changer l'uml état MAP*/

class MAP_Coffre{
	private :
		int idCoffre; 
		int x;
		int y;
		NomObjet nomObjet;
		TypeObjet typeObjet;
		
	public :
				
		/*
		* constructeurs
		* */
		
		MAP_Coffre(int idCoffre,int x,int y, NomObjet, TypeObjet);
		
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
		int getX();
		int getY();
		
		/*
		* setteurs
		* */
		void setX(int x);
		void setY(int y);
		
		/*
		* autres méthodes
		* */
		
		void transfert(MAP_Personnage);
		
};

#endif

