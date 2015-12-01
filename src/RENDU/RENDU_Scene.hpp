#ifndef RENDU_Scene_HPP
#define RENDU_Scene_HPP

#include "RENDU_VariablesGlobales.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include "RENDU_Surface.hpp"
#include "RENDU_Plan.hpp"


/* include ETAT ? */

class RENDU_Scene{
	
	protected:
		int hauteur;
		int largeur;
		//RENDU_Plan* plans;,
		sf::Window fenetre;
		
	public:
		/*
		 * Constructeur 
		 */
		RENDU_Scene();
		
		/*
		 * Destructeur 
		 */
		~RENDU_Scene();
		
		/*
		 * Getters
		 */
		int const getWidth();
		int const getHeight();
		int const getLayerCount();
		sf::Window getWindow();
		
		/*
		 * Setters
		 */
		//void setLayer(int idx, RENDU_Plan* plans); 
//		void setSurface(int idx, RENDU_Surface* surface);
		
		/*
		 * Methodes
		 */  
/*		void registerObservers(const ETAT::ETAT* s);
		void unregisterObservers(const ETAT::ETAT* s);
		void stateChanged(const ETAT::ETATEvent& e);
		void sync(int64_t temps);
		void update(int64_t temps);*/
};
#endif