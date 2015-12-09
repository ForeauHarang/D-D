#ifndef IA__H
#define IA__H


namespace IA {

  /// class IA_Manager - 
  class IA_Manager {
    // Attributes
  protected:
    MOTEUR_ListeAction* actions;
    MAP_Carte* map;
    // Operations
  public:
    IA_Manager(){}// ();
    ~IA_Manager(){}// ();
  };

  /// class IA_ComplexeDeplacement - 
  class IA_ComplexeDeplacement : public IA::IA_Manager {
    // Attributes
  private:
    MAP_Personnage* ia;
    int distanceMin;
    int indiceDistanceMin;
    std::vector<IA_DeplacementCase*> liste;
  protected:
    MOTEUR_ListeAction* actions;
    MAP_Carte* map;
    // Operations
  public:
    IA_ComplexeDeplacement (MOTEUR_ListeAction* actions, MAP_Personnage* ia, MAP_Carte* map);
    void  addChildrenToList (IA_DeplacementCase* pere);
    void  reachTarget (int xCible, int yCible, int i);
    void  addAction ();
    ~IA_ComplexeDeplacement(){}// ();
  };

  /// class IA_DeplacementCase - 
  class IA_DeplacementCase {
    // Associations
    // Attributes
  private:
    int  etage;
    IA_DeplacementCase* pere;
    int  x;
    int  y;
    MAP_Carte* carte;
    // Operations
  public:
    IA_DeplacementCase (int etage, int x, int y, MAP_Carte* carte);
    IA_DeplacementCase (int etage, int x, int y, IA_DeplacementCase* pere, MAP_Carte* carte);
    ~IA_DeplacementCase ();
    int  getX ();
    int  getY ();
    int  getSquareDistance (int x, int y, MAP_Carte* map);
    int  getSquareDistance (IA_DeplacementCase* cible, MAP_Carte* map);
    int  getStage ();
    IA_DeplacementCase* getFather ();
    MAP_Carte* getMap ();
  };

  /// class IA_IASimple - 
  class IA_IASimple : public IA::IA_Manager {
    // Attributes
  protected:
    MOTEUR_ListeAction* actions;
    MAP_Carte* map;
    // Operations
  public:
    IA_IASimple (MAP_Carte* map, MOTEUR_ListeAction* actions);
    ~IA_IASimple(){}// ();
    virtual void  reachTarget (MAP_Carte* map, int X1, int Y1, int X2, int Y2);
  };

};

#endif
