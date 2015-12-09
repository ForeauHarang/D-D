#ifndef TILEMAPNEW_HPP
#define TILEMAPNEW_HPP

#include "RENDU_VariablesGlobales.hpp"
#include "RENDU_ElementGraphique.hpp"
//#include "TileMap.hpp"
#include <SFML/Graphics/VertexArray.hpp>
#include "../MAP/MAP_Carte.hpp"


class TileMapnew : public RENDU_ElementGraphique // public public sf::Drawable, public sf::Transformable
{
	public:
		bool load();
		bool load(const string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height) ;
		virtual std::string getElemId() override;
		void setStringId(std::string name);
		void setMap(MAP_Carte* carte);
	private:

		void draw(sf::RenderTarget& target, sf::RenderStates states) const ;
		MAP_Carte* carte;
		std::string stringId="TileMap";
		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
};
#endif
