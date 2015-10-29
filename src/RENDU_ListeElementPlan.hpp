#ifndef RENDU_ListeElementPlan_HPP
#define RENDU_ListeElementPlan_HPP

#include "RENDU_Plan.hpp"
#include "RENDU_JeuDeTuile.hpp"

/* include ETAT */

class RENDU_ListeElementPlan : public RENDU_Plan{

	protected:
		//void update(const ETAT::ListeElement& listElement, int i);
		
	public:
		/*
		 * Constructeur 
		 */
		RENDU_ListeElementPlan();
		
		/*
		 * Destructeur 
		 */
		~RENDU_ListeElementPlan();
 
		
		/*
		 * Methodes
		 */  
		//void stateChanged(const ETAT::ETATEvent& e);
		
		/*
		 * Getters
		 */  
		MAP_Carte getCarteMap();
		FIGHT_Carte getCarteFight();
		
		/*
		 * Setters
		 */ 
		void setCarteMap(MAP_Carte carte);
		void setCarteFight(FIGHT_Carte carte);
		
		
	private:
		RENDU_JeuDeTuile jeuDeTuile;
		MAP_Carte carteMap;
		FIGHT_Carte carteFight;
};
#endif
