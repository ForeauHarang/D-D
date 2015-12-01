#ifndef RENDU_ELEMENTGRAPHIQUE_HPP
#define RENDU_ELEMENTGRAPHIQUE_HPP

#include <string>
#include "RENDU_VariablesGlobales.hpp"
#include <SFML/Graphics/VertexArray.hpp>

using std::string;

class RENDU_ElementGrapgique public sf::Drawable, public sf::Transformable{
	public :
		/*
		 * Constructeur 
		 */
		//MOTEUR_Action();
		
		/*
		 * Destructeur 
		 */
		//~MOTEUR_Action();
		
		/*
		 * Getters
		 */
		virtual int getElemId() = 0;
		/*
		 * Setters
		 */
		
		/*
		 * Methodes
		 */	 
		virtual void load(const string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height);
		//virtual void undo()=0;
		
};

#endif
