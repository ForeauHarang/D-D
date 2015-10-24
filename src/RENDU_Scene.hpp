#ifndef RENDU_Scene_HPP
#define RENDU_Scene_HPP

#include "RENDU_Surface.hpp"
#include "RENDU_Plan.hpp"
#include "RENDU_VariablesGlobales.hpp"

/* include ETAT ? */

class RENDU_Scene{

	protected:
		int hauteur;
		int largeur;
		RENDU_Plan* plans;
		
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
		
		/*
		 * Setters
		 */
		void setLayer(int idx, RENDU_Plan* plans); 
		void setSurface(int idx, RENDU_Surface* surface);
		
		/*
		 * Methodes
		 */  
		void registerObservers(const ETAT::ETAT* s);
		void unregisterObservers(const ETAT::ETAT* s);
		void stateChanged(const ETAT::ETATEvent& e);
		void sync(int64_t temps);
		void update(int64_t temps);
};
#endif
