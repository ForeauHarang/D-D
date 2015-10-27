#ifndef RENDU_Tuile_HPP
#define RENDU_Tuile_HPP

class RENDU_Tuile {
	public :
		/*
		 * Constructeur 
		 */
		RENDU_Tuile();
		
		/*
		 * Destructeur 
		 */
		virtual ~RENDU_Tuile();
		
		/*
		 * Methodes
		 */ 
		virtual bool const isAnimated()=0;
};
#endif;
