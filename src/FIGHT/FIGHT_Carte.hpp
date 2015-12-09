#ifndef FIGHT_CARTE_HPP
#define FIGHT_CARTE_HPP


#include "FIGHT_VariablesGlobales.hpp"
#include "FIGHT_Personnage.hpp"

//#include "FIGHT.hpp"


	class FIGHT_Carte {
	private :
		int nombreGentils;
		int nombreMechants;
		FIGHT_Personnage *listePersonnages[NBPERSO];
		int nombreTotal;


	public :
		/*
		* constructeurs
		* */

		FIGHT_Carte(int nbGentils, int nbMechants, FIGHT_Personnage *tableauPersonnage);

		/*
		* destructeurs
		* */

		~FIGHT_Carte();

		/*
		* getteurs
		* */

		int getNiceNumber();

		int getEvilNumber();

		FIGHT_Personnage *getListCharacters();

		/*
		* setteurs
		* */

		void setNiceNumber(int);

		void setEvilNumber(int);

		void removeCharacter(FIGHT_Personnage);

		/*
		* autres méthodes
		* */

};
#endif

