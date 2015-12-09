//
// Created by gabriel on 08/12/15.
//

#ifndef INC_3A_MOTEUR_HPP
#define INC_3A_MOTEUR_HPP

#include <string>
#include "../MAP/MAP.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define TAILLEBLOC 32
#define LISTEMAX 1024

using std::string;

#include "../MAP/MAP.hpp"

namespace MOTEUR{
    using std::string;
    using namespace MAP;
    class MOTEUR_Action;
    class MOTEUR_DeplacementPersonnage;
    class MOTEUR_ListeAction;
    class MOTEUR_QuitterProgramme;
    class MOTEUR_Regle;


}

#include "MOTEUR.h"

#endif //INC_3A_MOTEUR_HPP
