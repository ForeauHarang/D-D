#ifndef RENDU_StaticTuile_HPP
#define RENDU_StaticTuile_HPP

class RENDU_StaticTuile : public RENDU_Tuile{

	protected:
		int x;
		int y;
		int hauteur;
		int largeur;
		
	public:
		/*
		 * Constructeur 
		 */
		RENDU_StaticTuile(int x=0, int y=0, int largeur=0, int hauteur=0);
		
		/*
		 * Destructeur 
		 */
		~RENDU_StaticTuile();
		
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
