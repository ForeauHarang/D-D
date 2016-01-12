#include "ActionService.hpp"

ActionService::ActionService (ActionDB& actionDB) : AbstractService("/action"),
    actionDB(actionDB) {
    
}

HttpStatus ActionService::get (json::Value& out, int id) const {
    const int action = actionDB.getAction(id);
    if (!action)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid action id");
    out["id"] = action->id;
    return HttpStatus::OK;
}

HttpStatus ActionService::post (const Json::Value& in, int id) {
	const int action = actionDB.getAction(id);
	if (!action)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid action id");
    actionDB.setAction(id);
    return HttpStatus::NO_CONTENT;
}

HttpStatus ActionService::put (Json::Value& out,const Json::Value& in) {
    int id = in["id"].asInt();
    out["id"] = actionDB.addAction(id);
    return HttpStatus::CREATED;
}

HttpStatus ActionService::remove (int id) {
    const int action = actionDB.getAction(id);
    if (!action)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid action id");
    actionDB.removeAction(id);
    return HttpStatus::NO_CONTENT;
}

