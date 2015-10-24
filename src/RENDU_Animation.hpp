#ifndef RENDU_Animation_HPP
#define RENDU_Animation_HPP

#include "RENDU_Tuile.hpp"
#include "RENDU_Surface.hpp"

class RENDU_Animation {
	protected :
		int x;
		int y;
		float vitesse;
		int64_t debut;
		const RENDU_Tuile* tuile;
		//direction;
		
	public :
		int i;
		
		/*
		 * Constructeur 
		 */
		RENDU_Animation(int i, int x, int y, const RENDU_Tuile* a);
		
		/*
		 * Destructeur 
		 */
		~RENDU_Animation();
		
		/*
		 * Setters
		 */
		void setDirection(//);
		void setSpeed(float vitesse);
		
		/*
		* Méthodes
		*/
		void sync(int64_t temps);
		void update(int64_t temps, RENDU_Surface* surface);

};
#endif;