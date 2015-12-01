#ifndef MAP_QUETE_HPP
#define MAP_QUETE_HPP

#include "MAP_VariablesGlobales.hpp"
#include "MAP_Personnage.hpp"
//#include "MAP_Carte.hpp"
/* changer l'uml état MAP*/

class MAP_Quete{
	private :
		int idQuete;
		string donneur;
		int but;
		EtatQuete etat;
		
	public :
				
		/*
		* constructeurs
		* */
		
		MAP_Quete(int idQuete, string donneur, int but); /* état initial : REPOS */
		
		/*
		* destructeurs
		* */
		
		~MAP_Quete();
		
		/*
		* getteurs
		* */
		
		EtatQuete getState();
		MAP_Personnage getGiver();
		int getGoal();
		int getQuestId();
		
		/*
		* setteurs
		* */
		
		void setState(EtatQuete);
		
		/*
		* autres méthodes
		* */
		
};

#endif
