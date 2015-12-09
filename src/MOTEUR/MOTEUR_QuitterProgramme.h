#ifndef MOTEUR_QUITTERPROGRAMME__H
#define MOTEUR_QUITTERPROGRAMME__H

#include "MOTEUR_Action.h"

/// class MOTEUR_QuitterProgramme - 
class MOTEUR_QuitterProgramme : public MOTEUR_Action {
  // Attributes
protected:
  sf::RenderWindow* window;
  // Operations
public:
  MOTEUR_QuitterProgramme ();
  ~MOTEUR_QuitterProgramme ();
  virtual string  getActionId ();
  void  setWindow (sf::RenderWindow* window);
  virtual void  apply ();
};

#endif
