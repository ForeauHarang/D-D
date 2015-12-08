#ifndef MAP__H
#define MAP__H


namespace MAP {

  /// class MAP_Carte - 
  class MAP_Carte {
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
    // Operations
  public:
    MAP_Carte (int idCarte, int width, int height);
    MAP_Carte ();
    ~MAP_Carte ();
    MAP_Quete* getListQuests ();
    MAP_Coffre* getListChest ();
    int* getListImpassableElement ();
    const std::vector<int>& getMap ();
    int  getLevelValue (int x, int y);
    int  getWidthMap ();
    int  getHeightMap ();
    void  addCharacter (MAP_Personnag e);
    void  removeCharacter (MAP_Personnag e);
    void  addQuest (MAP_Quet e);
    void  removeQuest (MAP_Quet e);
    void  addChest (MAP_Coffr e);
    void  removeChest (MAP_Coffr e);
    void  addImpassableElement (in t, in t);
    void  removeImpassableElement (in t, in t);
    void  setWidthMap (int width);
    void  setHeightMap (int height);
    std::vector<MAP_Personnage*> getListCharacters ();
  };

  /// class MAP_Coffre - 
  class MAP_Coffre {
    // Associations
    MAP::MAP_Carte* listeCoffres;
    // Attributes
  private:
    int  idCoffre;
    int  x;
    int  y;
    NomObjet  nomObjet;
    TypeObjet  typeObjet;
    // Operations
  public:
    MAP_Coffre (int idCoffre, int x, int y, NomObje t, TypeObje t);
    ~MAP_Coffre ();
    NomObjet  getNameItem ();
    TypeObjet  getTypeItem ();
    int  getChestId ();
    int  getX ();
    int  getY ();
    void  setX (int x);
    void  setY (int y);
  };

  enum TypeObjet {
    ARME,
    ARMURE,
    POTION,
    QUETE
  };

  enum Race {
    HUMAIN,
    LOUP_GAROU,
    VAMPIRE
  };

  enum Profession {
    SOLDAT,
    VOLEUR,
    SORCIER
  };

  enum Groupe {
    NEUTRE,
    GENTIL,
    MECHANT
  };

  /// class MAP_Personnage - 
  class MAP_Personnage {
    // Associations
    MAP::MAP_Carte* listePersonnages;
    // Attributes
  private:
    int caracteristiques[NOMBRECARAC];
    Race race;
    Profession profession;
    std::string idPersonnage;
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
  };

  /// class MAP_InventairePersonnage - 
  class MAP_InventairePersonnage {
    // Associations
    MAP::MAP_Personnage inventaire;
    // Attributes
  private:
    MAP_ObjetInventaire* tableauSlots;
    bool inventaireOuvert;
    // Operations
  public:
    MAP_InventairePersonnage ();
    MAP_InventairePersonnage (MAP_ObjetInventaire* tableauSlots);
    ~MAP_InventairePersonnage ();
    MAP_ObjetInventaire getItemSlot (int numeroSlot);
    bool isInventoryOpen ();
    void moveItemToSlot (int numeroSlot, int origine);
     ();
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
    MAP_ObjetInventaire (in t);
    ~MAP_ObjetInventaire ();
    void  setSlot (in t);
    TypeObjet  getTypeItem ();
    NomObjet  getItemName ();
    int  getSlot ();
  };

  /// class MAP_Quete - 
  class MAP_Quete {
    // Associations
    MAP::MAP_Carte* listeQuetes;
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
    void  setState (EtatQuet e);
  };

  enum nomObjet {
    COUTEAU,
    PISTOLET,
    FUSIL,
    VETEMENT,
    KEVLAR,
    POTION_SOIN,
    POISON,
    LIVRE,
    POULET,
    BALLE_ARGENT,
    SAC_SANG,
    PIEUX
  };

};

#endif
