#ifndef FIGHT_PERSONNAGE_HPP
#define FIGHT_PERSONNAGE_HPP

#include "FIGHT_VariablesGlobales.hpp"
#include "FIGHT_Competence.hpp"

/* changer l'uml : personnage possede compétence; il ne la référence plus */

class FIGHT_Personnage{
	private :
		FIGHT_Competence* listeCompetences[]; // cf fin du header
		int* caracteristiques; // cf fin du header
		FIGHT_Race race;
		FIGHT_Groupe groupe;
		FIGHT_Profession profession;
		FIGHT_NomArme arme;
		FIGHT_NomArmure armure;
		FIGHT_NomPotion potion;
		string idPersonnage;
		bool vivant;
		
	public :
				
		/*
		* constructeurs
		* */
		
		FIGHT_Personnage(int niveau, int x, int y, FIGHT_Race race, 
							FIGHT_Groupe groupe, FIGHT_Profession profession, FIGHT_NomArme arme, FIGHT_NomArmure armure,
							FIGHT_NomPotion potion, string idPersonnage);
		
		/*
		* destructeurs
		* */
		
		~FIGHT_Personnage();
		
		/*
		* getteurs
		* */
		int getStr();
		int getDex();
		int getIntel();
		int getHp();
		int getMana();
		int getLevel();
		FIGHT_Profession getJob();
		FIGHT_Groupe getGroup();
		FIGHT_Race getRace();
		FIGHT_NomArme getWeapon();
		FIGHT_NomArmure getArmor();
		FIGHT_NomPotion getPotion();
		string getCharacterId();
		
		int getXpos();
		int getYpos();
		
		bool getAlive();
		
		/*
		* setteurs
		* */
		
		void setHP(int);
		void setMana(int);
		void setPotion();
		void setDeath();
		
		/*
		* autres méthodes
		* */
		void useCompetence(FIGHT_Personnage cible, int numComp);
};

#endif

/* compétences :
 * comp[0] : ATTAQUER
 * comp[1] : BOULE DE FEU
 * comp[2] : MORSURE
 * comp[3] : GRIFFE
 * comp[4] : BOUCLIER
 * comp[5] : POTION
 */





/* caracteristiques :
 * carac[0] : force
 * carac[1] : dexterite : utilisé pour déterminer si on touche/est touché
 * carac[2] : intelligence
 * carac[3] : niveau
 * carac[4] : pv
 * carac[5] : mana
 * carac[6] : x
 * carac[7] : y
 * carac[8] : 
 * carac[9] :
 * 
 * 
 * 
 * 
 * */
