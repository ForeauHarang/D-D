#ifndef MOTEUR_ACTION_HPP
#define MOTEUR_ACTION_HPP

#include <string>
using std::string;

class MOTEUR_Action {
	public :
		/*
		 * Constructeur 
		 */
		//MOTEUR_Action();
		
		/*
		 * Destructeur 
		 */
		//~MOTEUR_Action();
		
		/*
		 * Getters
		 */
		virtual string getActionId()=0;
		/*
		 * Setters
		 */
		
		/*
		 * Methodes
		 */	 
		virtual void apply()=0;
		//virtual void undo()=0;
		
};

#endif
