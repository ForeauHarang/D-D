#ifndef RENDU__H
#define RENDU__H


namespace RENDU {

  /// class RENDU_Fenetre - 
  class RENDU_Fenetre {
    // Attributes
  public:
    std::vector<RENDU_ElementGraphique*> listeElementGraphique;
  private:
    sf::RenderWindow* window;
    MAP_Carte* map1;
    // Operations
  public:
    RENDU_Fenetre (sf::RenderWindow* window, MAP_Carte* map1);
    ~RENDU_Fenetre ();
    void  afficherElementGraphique ();
    void  afficherFenetre ();
    void  addElementToList (RENDU_ElementGraphique* element);
  };

  /// class RENDU_ElementGraphique : public sf::Drawable, public sf::Transformable - 
  class RENDU_ElementGraphique : public sf::Drawable, public sf::Transformable {
    // Associations
    // Operations
  public:
    virtual std::string  getElemId()=0;// ();
    virtual bool  load()=0;// ();
    RENDU_ElementGraphique(){}// ();
    ~RENDU_ElementGraphique(){}// ();
  };

  /// class RENDU_Sprite : public RENDU_ElementGraphique{// - 
  class RENDU_Sprite : public RENDU_ElementGraphique{// : public RENDU::RENDU_ElementGraphique : public sf::Drawable, public sf::Transformable {
    // Attributes
  private:
    std::string  elementString;
    int  X;
    int  Y;
    int  DirectionX;
    int  DirectionY;
    std::string  stringId;
    MAP_Personnage* personnagePtr;
    // Operations
  public:
    RENDU_Sprite (std::string path, std::string id, MAP_Personnage* personnagePtr);
    ~RENDU_Sprite(){}// ();
    std::string  getElementString ();
    int  getX ();
    int  getY ();
    int  getDirectionX ();
    int  getDirectionY ();
    virtual std::string  getElemId ();
    MAP_Personnage* getCharacterPtr ();
    void  setElementString (std::string path);
    void  setX (int X);
    void  setY (int Y);
    void  setDirectionX (int dirX);
    void  setDirectionY (int dirY);
    void  setElementId (std::string stringId);
    virtual bool  load ();
  private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;// ();
  };

  /// class TileMapnew : public RENDU_ElementGraphique{// - 
  class TileMapnew : public RENDU_ElementGraphique{// : public RENDU::RENDU_ElementGraphique : public sf::Drawable, public sf::Transformable {
    // Attributes
  private:
    MAP_Carte* carte;
    sf::VertexArray  m_vertices;
    sf::Texture  m_tileset;
    std::string stringId="TileMap";
    // Operations
  public:
    bool  load ();
    bool  load (const string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height);
    virtual std::string  getElemId ();
    void  setStringId (std::string name);
    void  setMap (MAP_Carte* carte);
    TileMapnew(){}// ();
    ~TileMapnew(){}// ();
  private:
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;// ();
  };

};

#endif
