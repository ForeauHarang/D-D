#ifndef MOTEUR_LISTEACTION__H
#define MOTEUR_LISTEACTION__H

/// class MOTEUR_ListeAction - 
class MOTEUR_ListeAction {
  // Attributes
private:
  int  nombreAction;
  MOTEUR_Regle  regles;
  MOTEUR_Action* listeAction;
  bool resterDansLaBoucle;
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

#endif
