#ifndef RENDU_ANIMATEDTUILE_HPP
#define RENDU_ANIMATEDTUILE_HPP

#include "RENDU_Tuile.hpp"

class RENDU_AnimatedTuile : public RENDU_Tuile{

	public:
		float taux;
		const RENDU_Tuile* tuile;
		/*
		 * Constructeur 
		 */
		RENDU_AnimatedTuile(float taux=10);
		
		/*
		 * Destructeur 
		 */
		~RENDU_AnimatedTuile();
		
		/*
		 * Getters
		 */
		float const getRate();
		const RENDU_Tuile* const getTile(int64_t temps);
		const RENDU_Tuile* const getTile(int i);
		int const getTilecount();
		
		/*
		 * Setters
		 */
		void setRate(float taux); 
		void setTile(int i, RENDU_Tuile* tuile);
		
		/*
		 * Methodes
		 */  
		 bool const isAnimated() override;
		 void addTile(RENDU_Tuile* tuile);
};
#endif
