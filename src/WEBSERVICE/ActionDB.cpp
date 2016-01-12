#include "ActionDB.hpp"

ActionDB::ActionDB() : idseq(1) {
    
}

const int ActionDB::getAction (int id) const {
    auto ite = actions.find(id);
    if (ite == actions.cend())
        return nullptr;
    return ite->second.get();
}

int ActionDB::addAction (int id) {
    int id = idseq++;
    actions.insert(std::make_pair(id,std::move(action)));
    return id;
}

void ActionDB::setAction (int id) {
    actions[id] = std::move(action);
    if (id > idseq) {
        idseq = id;
    }
}

void ActionDB::removeAction (int id) {
    auto ite = actions.find(id);
    if (ite == actions.end())
        return;
    actions.erase(ite);
}


