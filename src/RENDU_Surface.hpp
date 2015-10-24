#ifndef RENDU_Surface_HPP
#define RENDU_Surface_HPP

class RENDU_Surface{
		
	public:
		/*
		 * Constructeur 
		 */
		RENDU_Surface();
		
		/*
		 * Destructeur 
		 */
		~RENDU_Surface();
 
		
		/*
		 * Methodes
		 */  
		void clear();
		void loadTexture(const char* imageFile);
		
		/*
		 * Setters
		 */
		void setSpriteCount(int n);
		void setSprieLocation(int x, int y, int i);
		void setSpriteTexture(int i, const RENDU_StaticTuile* tex);
		
};
#endif
