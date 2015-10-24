#ifndef RENDU_ListeElementPlan_HPP
#define RENDU_ListeElementPlan_HPP

#include "RENDU_Plan.hpp"

/* include ETAT */

class RENDU_ListeElementPlan : public RENDU_Plan{

	protected:
		void update(const ETAT::ListeElement& listElement, int i);
		
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
		void stateChanged(const ETAT::ETATEvent& e);
};
#endif
