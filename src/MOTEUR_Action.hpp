#ifndef MOTEUR_ACTION_HPP
#define MOTEUR_ACTION_HPP


class MOTEUR_Action {
	public :
		/*
		 * Constructeur 
		 */
		MOTEUR_Action();
		
		/*
		 * Destructeur 
		 */
		virtual ~MOTEUR_Action()=0;
		
		/*
		 * Getters
		 */
				
		/*
		 * Setters
		 */
		
		/*
		 * Methodes
		 */	 
		virtual void apply()=0;
		//virtual void undo()=0;
		
};

#enfif
