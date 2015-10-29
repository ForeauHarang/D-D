#ifndef RENDU_Plan_HPP
#define RENDU_Plan_HPP

#include "RENDU_JeuDeTuile.hpp"
#include "RENDU_Surface.hpp"
#include "RENDU_Animation.hpp"

class RENDU_Plan{

	private:
		//animation
	
	protected:
		const RENDU_JeuDeTuile* jeuDeTuile;
		RENDU_Surface* surface;
		
	public:
		/*
		 * Constructeur 
		 */
		RENDU_Plan();
		
		/*
		 * Destructeur 
		 */
		~RENDU_Plan();
		
		/*
		 * Getters
		 */
		const RENDU_JeuDeTuile* const getTileSet();
		
		/*
		 * Setters
		 */
		void setTileSet(const RENDU_JeuDeTuile* jeuDeTuile); 
		void setSurface(RENDU_Surface* surface);
		//void setAnimation(int i, RENDU_Animation* a);
		
		/*
		 * Methodes
		 * perso
		 * Srpite sprite;
		 * setpos = perso.x,y
		 * sprite.loadfromfile(getelementtile(perso)
		*/
		
		 
		//void printText(int x, int y, const char* msg, int spriteIdx, int w, int h);
		//void sync(int64_t temps);
		//void update(int64_t temps);
};
#endif
