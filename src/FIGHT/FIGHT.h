#ifndef FIGHT__H
#define FIGHT__H


namespace FIGHT {

  enum FIGHT_NomCompetence {
    FIGHT_ATTAQUER,
    FIGHT_BOULEDEFEU,
    FIGHT_MORSURE,
    FIGHT_GRIFFE,
    FIGHT_BOUCLIER,
    FIGHT_POTION
  };

  enum FIGHT_Race {
    FIGHT_HUMAIN,
    FIGHT_LOUP_GAROU,
    FIGHT_VAMPIRE,
    FIGHT_MONSTRE
  };

  enum FIGHT_Profession {
    FIGHT_SOLDAT,
    FIGHT_VOLEUR,
    FIGHT_SORCIER
  };

  enum FIGHT_NomArme {
    FIGHT_PASDENOMARME,
    FIGHT_COUTEAU,
    FIGHT_PISTOLET,
    FIGHT_FUSIL
  };

  enum FIGHT_NomPotion {
    FIGHT_PASDENOMPOTION,
    FIGHT_SOIN,
    FIGHT_MANA,
    FIGHT_POISON
  };

  enum FIGHT_Groupe {
    FIGHT_GENTIL,
    FIGHT_MECHANT
  };

  enum FIGHT_NomArmure {
    FIGHT_PASDENOMARMURE,
    FIGHT_VETEMENT,
    FIGHT_KEVLAR
  };

  /// class FIGHT_Personnage - 
  class FIGHT_Personnage {
    // Attributes
  private:
    int* caracteristiques;
    FIGHT_Race  race;
    FIGHT_Groupe  groupe;
    FIGHT_Profession  profession;
    FIGHT_NomArme  arme;
    FIGHT_NomArmure  armure;
    FIGHT_NomPotion  potion;
    string  idPersonnage;
    bool  vivant;
    // Operations
  public:
    FIGHT_Personnage (int niveau, int x, int y, FIGHT_Race race, FIGHT_Groupe groupe, FIGHT_Profession profession, FIGHT_NomArme arme, FIGHT_NomArmure armure, FIGHT_NomPotion potion, string idPersonnage);
    ~FIGHT_Personnage ();
    int  getStr ();
    int  getDex ();
    int  getIntel ();
    int  getHp ();
    int  getMana ();
    int  getLevel ();
    FIGHT_Profession  getJob ();
    FIGHT_Groupe  getGroup ();
    FIGHT_Race  getRace ();
    FIGHT_NomArme  getWeapon ();
    FIGHT_NomArmure  getArmor ();
    FIGHT_NomPotion  getPotion ();
    string  getCharacterId ();
    int  getXpos ();
    int  getYpos ();
    bool  getAlive ();
    void  setHP (in t);
    void  setMana (in t);
    void  setPotion ();
    void  setDeath ();
    void  useCompetence (FIGHT_Personnage cible, int numComp);
  };

  /// class FIGHT_Competence - 
  class FIGHT_Competence {
    // Associations
    FIGHT::FIGHT_Personnage* competences;
    // Attributes
  private:
    FIGHT_NomCompetence  competence;
    int  degats;
    int  soins;
    int  bouclier;
    int  coutMana;
    bool  utilisable;
    // Operations
  public:
    FIGHT_Competence (FIGHT_NomCompetence nomComp, int force, int intel, int niveau, FIGHT_Race race, FIGHT_Profession profession, FIGHT_NomArme arme, FIGHT_NomPotion potion);
    ~FIGHT_Competence ();
    int  getDamage ();
    int  getHeal ();
    int  getShield ();
    int  getManaCost ();
    bool  isAvailable ();
    FIGHT_NomCompetence  getSkillName ();
    void  SkillLevelUp (int niveau);
  };

  /// class FIGHT_Carte - 
  class FIGHT_Carte {
    // Attributes
  private:
    int  nombreGentils;
    int  nombreMechants;
    int  nombreTotal;
    // Operations
  public:
    FIGHT_Carte (int nbGentils, int nbMechants, FIGHT_Personnage* tableauPersonnage);
    ~FIGHT_Carte ();
    int  getNiceNumber ();
    int  getEvilNumber ();
    FIGHT_Personnage* getListCharacters ();
    void  setNiceNumber (in t);
    void  setEvilNumber (in t);
    void  removeCharacter (FIGHT_Personnag e);
  };

};

#endif
