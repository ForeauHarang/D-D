#ifndef USERDB__H
#define USERDB__H

#include "Action.h"

/// class ActionDB - 
class ActionDB {
  // Associations
  // Attributes
protected:
	int id;
  // Operations
public:
  ActionDB ();
  const int getAction (int id) const;
  int addAction (int id);
  void setAction (int id);
  void removeAction (int id);
};

#endif
