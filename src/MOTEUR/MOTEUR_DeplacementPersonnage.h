#ifndef MOTEUR_DEPLACEMENTPERSONNAGE__H
#define MOTEUR_DEPLACEMENTPERSONNAGE__H

#include "MOTEUR_Action.h"

/// class MOTEUR_DeplacementPersonnage - 
class MOTEUR_DeplacementPersonnage : public MOTEUR_Action {
  // Attributes
protected:
  int  dx;
  int  dy;
  MAP_Personnage* ptrperso;
  // Operations
public:
  MOTEUR_DeplacementPersonnage ();
  MOTEUR_DeplacementPersonnage (int dx, int dy, MAP_Personnage* ptrperso);
  virtual ~MOTEUR_DeplacementPersonnage ();
  int  getX ();
  int  getY ();
  int  getDX ();
  int  getDY ();
  MAP_Personnage* getCharacterPtr ();
  virtual virtual string  getActionId () = 0;
  virtual virtual void  apply () = 0;
};

#endif
