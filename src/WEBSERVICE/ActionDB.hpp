#ifndef __ActionDB_hpp__
#define __ActionDB_hpp__

#include <memory>
#include <map>

using std::unique_ptr;
using std::map;

#include "Action.hpp"
#include "ActionDB.h"

template<class T,typename ... Args>
std::unique_ptr<T> make_unique(Args ... args) {
    return std::unique_ptr<T>(new T(args ...));
}

#endif

