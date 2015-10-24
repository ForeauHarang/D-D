#ifndef ETAT_EtatObserver_HPP
#define ETAT_EtatObserver_HPP

class ETAT_EtatObserver{
		
	public:
		/*
		 * Constructeur 
		 */
		ETAT_EtatObserver();
		
		/*
		 * Destructeur 
		 */
		~ETAT_EtatObserver();
		
		/*
		 * Methodes
		 */  
		void stateChanged(const ETATEvent& );
};
#endif
