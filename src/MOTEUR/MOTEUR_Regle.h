#ifndef MOTEUR_REGLE__H
#define MOTEUR_REGLE__H

#include "MOTEUR_ListeAction.h"

/// class MOTEUR_Regle - 
class MOTEUR_Regle {
  // Associations
  // Attributes
private:
  MAP_Carte* CARTE_carte;
  // Operations
public:
  MOTEUR_Regle ();
  MOTEUR_Regle (MAP_Carte* carte);
  ~MOTEUR_Regle ();
  MAP_Carte* getCARTE_Map ();
  void  setCARTE_Map (MAP_Carte );
  bool  isAvailable (MOTEUR_DeplacementPersonnage* );
};

#endif
