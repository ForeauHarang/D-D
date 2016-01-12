#ifndef USERSERVICE__H
#define USERSERVICE__H

#include "HttpStatus.h"
#include "AbstractService.h"
#include "ActionDB.h"

/// class ActionService - 
class ActionService : public AbstractService {
  // Associations
  // Attributes
protected:
  ActionDB& actionDB;
  // Operations
public:
  ActionService (ActionDB& actionDB);
  HttpStatus get (Json::Value& out, int id) const;
  HttpStatus post (const Json::Value& in, int id);
  HttpStatus put (Json::Value& out, const Json::Value& in);
  HttpStatus remove (int id);
};

#endif
