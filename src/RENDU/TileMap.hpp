#ifndef test_hpp
#define test_hpp

#include "RENDU_VariablesGlobales.hpp"
#include "RENDU_ElementGraphique.hpp"
#include "TileMap.hpp"
#include <SFML/Graphics/VertexArray.hpp>

class TileMap : public sf::Drawable, public sf::Transformable //public RENDU_ElementGraphique // public public sf::Drawable, public sf::Transformable
{
public:

    virtual bool load(const string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height) ;


private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const ;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};
#endif
