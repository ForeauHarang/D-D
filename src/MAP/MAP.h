#ifndef MAP__H
#define MAP__H


namespace MAP {

  /// class MAP_Personnage - 
  class MAP_Personnage {
    // Associations
    // Attributes
  private:
    int caracteristiques[NOMBRECARAC];
    Race race;
    Profession profession;
    std::string idPersonnage;
    Groupe groupe;
    // Operations
  public:
    MAP_Personnage (int[NOMBRECARAC] , Race , Profession , Groupe , string );
    MAP_Personnage (Race , Profession , Groupe , string );
    MAP_Personnage (string );
    int getX ();
    int getY ();
    int* getCharacteristics ();
    Race getRace ();
    Profession getJob ();
    Groupe getGroup ();
    string getCharacterId ();
    void set1characteristicto (int numeroCarac, int nouvelleValeur);
    void setX (int x);
    void setY (int y);
    void openInventory ();
    void closeInventory ();
    ~MAP_Personnage ();
  };

  /// class MAP_Quete - 
  class MAP_Quete {
    // Attributes
  private:
    int  idQuete;
    string  donneur;
    int  but;
    EtatQuete  etat;
    // Operations
  public:
    MAP_Quete (int idQuete, string donneur, int but);
    ~MAP_Quete ();
    EtatQuete  getState ();
    MAP_Personnage  getGiver ();
    int  getGoal ();
    int  getQuestId ();
    void  setState (EtatQuete etatQuete);
  };

  /// class MAP_Coffre - 
  class MAP_Coffre {
    // Associations
    // Attributes
  private:
    int  idCoffre;
    int  x;
    int  y;
    NomObjet  nomObjet;
    TypeObjet  typeObjet;
    // Operations
  public:
    MAP_Coffre (int idCoffre, int x, int y, NomObjet nomObjet, TypeObjet typeObjet);
    ~MAP_Coffre ();
    NomObjet  getNameItem ();
    TypeObjet  getTypeItem ();
    int  getChestId ();
    int  getX ();
    int  getY ();
    void  setX (int x);
    void  setY (int y);
  };

  /// class MAP_Carte - 
  class MAP_Carte {
    // Associations
    // Attributes
  private:
    int  idCarte;
    int* listeElementsInfranchissables;
    int  nombrePersonnages;
    int  nombreQuetes;
    int  nombreCoffres;
    int  nombreElementsInfranchissables;
    int  height;
    int  width;
    std::vector<int>  level;
    std::vector<MAP_Personnage*> listePersonnages;
    MAP_Coffre* listeCoffres[NBCOFFRES];
    MAP_Quete* listeQuetes[NBQUETES];
    // Operations
  public:
    MAP_Carte (int idCarte, int width, int height);
    MAP_Carte ();
    ~MAP_Carte ();
    MAP_Quete* getListQuests ();
    MAP_Coffre* getListChest ();
    int* getListImpassableElement ();
    const std::vector<int>& getMap() const;// ();
    int  getLevelValue(int x, int y) const;// (int x, int y);
    int  getWidthMap ();
    int  getHeightMap ();
    void  addCharacter (MAP_Personnage* perso);
    void  removeCharacter (MAP_Personnage perso);
    void  addQuest (MAP_Quete quete);
    void  removeQuest (MAP_Quete quete);
    void  addChest (MAP_Coffre coffre);
    void  removeChest (MAP_Coffre coffre);
    void  addImpassableElement (int x, int y);
    void  removeImpassableElement (int x, int y);
    void  setWidthMap (int width);
    void  setHeightMap (int height);
    std::vector<MAP_Personnage*> getListCharacters ();
  };

  /// class MAP_InventairePersonnage - 
  class MAP_InventairePersonnage {
    // Associations
    // Attributes
  private:
    MAP_ObjetInventaire *tableauSlots[NOMBRESLOTS];
    bool inventaireOuvert;
    // Operations
  public:
    MAP_InventairePersonnage ();
    MAP_InventairePersonnage (MAP_ObjetInventaire* tableauSlots[NOMBRESLOTS]);
    ~MAP_InventairePersonnage ();
    MAP_ObjetInventaire getItemInSlot (int numeroSlot);
    bool isInventoryOpen ();
    void moveItemToSlot (int numeroSlot, int origine);
    void addItemInBag (TypeObjet , NomObjet );
    void closeInventory ();
    void openInventory ();
    bool isSlotFree (int numeroSlot);
    bool isSlotOK (MAP_ObjetInventaire objetInventaire, int numeroSlot);
  };

  /// class MAP_ObjetInventaire - 
  class MAP_ObjetInventaire {
    // Associations
    // Attributes
  private:
    TypeObjet  typeObjet;
    NomObjet  nomObjet;
    int  slot;
    // Operations
  public:
    MAP_ObjetInventaire (TypeObjet , NomObjet , int );
    MAP_ObjetInventaire (int );
    ~MAP_ObjetInventaire ();
    void  setSlot (int );
    TypeObjet  getTypeItem ();
    NomObjet  getItemName ();
    int  getSlot ();
  };

};

#endif
