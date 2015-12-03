#ifndef RENDU_DebugPlan_HPP
#define RENDU_DebugPlan_HPP

#include "RENDU_Plan.hpp"

/* include ETAT */

class RENDU_DebugPlan : public RENDU_Plan{
		
	public:
		/*
		 * Constructeur 
		 */
		RENDU_DebugPlan();
		
		/*
		 * Destructeur 
		 */
		~RENDU_DebugPlan();
 
		
		/*
		 * Methodes
		 */  
		void stateChanged(const ETAT::ETATEvent& e);
		void printGridValue(int* valeurs, int n);
};
#endif
