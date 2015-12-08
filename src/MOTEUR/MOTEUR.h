#ifndef MOTEUR__H
#define MOTEUR__H


namespace MOTEUR {

  /// class MOTEUR_Regle - 
  class MOTEUR_Regle {
    // Attributes
  private:
    MAP_Carte* CARTE_carte;
    // Operations
  public:
    MOTEUR_Regle ();
    MOTEUR_Regle (MAP_Carte* carte);
    ~MOTEUR_Regle ();
    MAP_Carte* getCARTE_Map ();
    void  setCARTE_Map (MAP_Cart e);
    bool  isAvailable (MOTEUR_DeplacementPersonnag e);
  };

  /// class MOTEUR_ListeAction - 
  class MOTEUR_ListeAction {
    // Associations
    MOTEUR::MOTEUR_Regle regles;
    // Attributes
  private:
    int  nombreAction;
    MOTEUR_Regle  regles;
    // Operations
  public:
    MOTEUR_ListeAction ();
    MOTEUR_ListeAction (MAP_Carte* carte);
    ~MOTEUR_ListeAction ();
    MOTEUR_Action* getActionFromList (int placeDansListe);
    int  getActionNumber ();
    void  addAction (MOTEUR_Action* action);
    void  removeAction (int placeDansListe);
    void  apply ();
  };

  /// class MOTEUR_Action - 
  class MOTEUR_Action {
    // Associations
    // Operations
  public:
    virtual string  getActionId ();
    virtual void  apply ();
  };

  /// class MOTEUR_DeplacementPersonnage - 
  class MOTEUR_DeplacementPersonnage : public MOTEUR::MOTEUR_Action {
    // Attributes
  protected:
    int  dx;
    int  dy;
    MAP_Personnage* ptrperso;
    // Operations
  public:
    MOTEUR_DeplacementPersonnage ();
    MOTEUR_DeplacementPersonnage (int dx, int dy, MAP_Personnage* ptrperso);
    ~MOTEUR_DeplacementPersonnage ();
    int  getX ();
    int  getY ();
    int  getDX ();
    int  getDY ();
    MAP_Personnage* getCharacterPtr ();
    virtual string  getActionId ();
    virtual void  apply ();
  };

};

#endif
