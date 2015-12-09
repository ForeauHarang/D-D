#ifndef MOTEUR_ACTION__H
#define MOTEUR_ACTION__H

#include "MOTEUR_ListeAction.h"

/// class MOTEUR_Action - 
class MOTEUR_Action {
  // Associations
  // Operations
public:
  virtual virtual string  getActionId () = 0;
  virtual virtual void  apply () = 0;
};

#endif
