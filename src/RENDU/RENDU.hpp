//
// Created by gabriel on 09/12/15.
//

#ifndef INC_3A_RENDU_HPP
#define INC_3A_RENDU_HPP

#include <string>
#include "RENDU_VariablesGlobales.hpp"
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <cstdio>

#include "../MAP/MAP.hpp"

#ifndef TAILLEBLOC
    #define TAILLEBLOC 32
#endif

namespace RENDU{
    using namespace MAP;
    class RENDU_ElementGraphique;
    class RENDU_Fenetre;
    class RENDU_Sprite;
    class TileMapnew;
}

#include "RENDU.h"

#endif //INC_3A_RENDU_HPP
