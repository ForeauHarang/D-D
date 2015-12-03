
#ifndef FIGHT_COMPETENCE_HPP
#define FIGHT_COMPETENCE_HPP

#include "FIGHT_VariablesGlobales.hpp"

class FIGHT_Competence{
	private :
		FIGHT_NomCompetence competence;
		int degats;
		int soins;
		int bouclier;
		int coutMana;
		bool utilisable;
	public :
		
		/*
		* constructeurs
		* */
		
		FIGHT_Competence(FIGHT_NomCompetence nomComp,int force, int intel, int niveau, FIGHT_Race race, FIGHT_Profession profession, FIGHT_NomArme arme, FIGHT_NomPotion potion);
		
		/*
		* destructeurs
		* */
		
		~FIGHT_Competence();
		
		/*
		* getteurs
		* */
		
		int getDamage();
		int getHeal();
		int getShield();
		int getManaCost();
		bool isAvailable();
		FIGHT_NomCompetence getSkillName();
		/*
		* setteurs
		* */
		
		void SkillLevelUp(int niveau);
		
		/*
		* autres méthodes
		* */
		
};

#endif
