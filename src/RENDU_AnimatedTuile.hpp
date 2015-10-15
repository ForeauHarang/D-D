#ifndef RENDU_ANIMATEDTUILE_HPP
#define RENDU_ANIMATEDTUILE_HPP

class AnimatedTuile{

	public:
		float taux;
		const RENDU_Tuile* 
		/*
		 * Constructeur 
		 */
		StaticTuile(int x=0, int y=0, int largeur=0, int hauteur=0);
		
		/*
		 * Destructeur 
		 */
		~StaticTuile();
		
		/*
		 * Getters
		 */
		int const getX();
		int const getY();
		int const getWidth();
		int const getHeight();
		
		/*
		 * Setters
		 */
		void setX(int x); 
		void setY(int y);
		void setWidth(int largeur);
		void setHeight(int hauteur); 
		
		/*
		 * Methodes
		 */  
		 bool const isAnimated() override;
};
#endif
