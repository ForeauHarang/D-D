#ifndef MAP_OBJETINVENTAIRE_HPP
#define MAP_OBJETINVENTAIRE_HPP

#include "MAP_VariablesGlobales.hpp"

/* changer l'uml état MAP*/

class MAP_ObjetInventaire{
	private :
		TypeObjet typeObjet;
		NomObjet nomObjet;
		int slot;
	
	public :
	
		/*
		* constructeurs
		* */
		
		MAP_ObjetInventaire(TypeObjet, NomObjet, int);
		MAP_ObjetInventaire(int);
		
		/*
		* destructeurs
		* */
		
		~MAP_ObjetInventaire();
		
		/*
		* setteurs
		* */
		
		void setSlot(int);
		
		/*
		* getters
		* */
		
		TypeObjet getTypeItem();
		NomObjet getItemName();
		int getSlot();
		
		/*
		* autres méthodes
		* */
		
};

#endif
