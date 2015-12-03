#ifndef RENDU_EtatPlan_HPP
#define RENDU_EtatPlan_HPP

#include "RENDU_Plan.hpp"

/* include ETAT */

class RENDU_EtatPlan : public RENDU_Plan{
		
	public:
		/*
		 * Constructeur 
		 */
		RENDU_EtatPlan();
		
		/*
		 * Destructeur 
		 */
		~RENDU_EtatPlan();
 
		
		/*
		 * Methodes
		 */  
		void stateChanged(const ETAT::ETATEvent& e);
};
#endif
