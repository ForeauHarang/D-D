#ifndef RENDU_StaticTuile_HPP
#define RENDU_StaticTuile_HPP

#include "RENDU_VariablesGlobales.hpp"
#include "RENDU_Tuile.hpp"

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
		RENDU_StaticTuile():RENDU_Tuile(){}
		RENDU_StaticTuile(int x, int y, int largeur, int hauteur):RENDU_Tuile(){
			this->x=x;
			this->y=y;
			this->largeur=largeur;
			this->hauteur=hauteur;
		}
		
		/*
		 * Destructeur 
		 */
		~RENDU_StaticTuile(){}
		
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
		 bool const isAnimated();
};
#endif
