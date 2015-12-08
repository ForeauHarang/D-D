
namespace RENDU {

  /// class ElementGraphique - 
  class ElementGraphique {
    // Operations
  public:
    virtual string getElementId () = 0;
  };

  /// class RENDU_Fenetre - référence et affiche les RENDU_ElementGraphique s
  class RENDU_Fenetre {
    // Associations
    RENDU::ElementGraphique* unnamed;
    // Attributes
  public:
    MAP::MAP_Carte* map1;
  private:
    std::vector<ElementGraphique*> listeElementGraphique;
    sf::RenderWindow * window;
    // Operations
  public:
    void afficherElementGraphique ();
    void afficherFenetre ();
    void addElementToList (ElementGraphique* Element);
    void removeElementFromList (string ElementId);
  };

  /// class TileMap - 
  class TileMap : public ElementGraphique {
    // Attributes
  public:
    MAP::MAP_Carte* carte;
  private:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    string StringId;
    // Operations
  public:
    bool load (const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height);
    string getElementId ();
    bool load ();
    void setElementId (strindId string);
    void setMap (MAP_Carte* carte);
  private:
    void const draw (sf::RenderTarget& target, sf::RenderStates states);
  };

  /// class RENDU_Sprite - 
  class RENDU_Sprite : public ElementGraphique {
    // Attributes
  public:
    int DirectionY;
  private:
    std::string ElementString;
    int X;
    int Y;
    int DirectionX;
    string stringId;
    MAP_Personnage* personnagePtr;
    // Operations
  public:
    int getDirectionY ();
    int getElementId ();
    int getDirectionX ();
    string getElementId ();
    int getX ();
    int getY ();
    void setX (int X);
    void setY (int Y);
    std::string setElementString ();
    void setDirectionX (int dirX);
    void setDirectionY (int dirY);
    void setElementId (string stringId);
    MAP::MAP_Personnage* getCharacterPtr() ();
  };

};

