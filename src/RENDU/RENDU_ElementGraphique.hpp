#ifndef RENDU_ELEMENTGRAPHIQUE_HPP
#define RENDU_ELEMENTGRAPHIQUE_HPP

#include <string>
#include "RENDU_VariablesGlobales.hpp"
#include <SFML/Graphics/VertexArray.hpp>	

#ifndef TAILLEBLOC
#define TAILLEBLOC 32
#endif

using std::string;

class RENDU_ElementGraphique : public sf::Drawable, public sf::Transformable{
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
		virtual std::string getElemId() = 0;
		/*
		 * Setters
		 */
		
		/*
		 * Methodes
		 */
		//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const=0;
		virtual bool load()=0;
		//virtual void undo()=0;
		
};

#endif
