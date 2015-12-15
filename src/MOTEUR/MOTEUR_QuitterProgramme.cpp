#include "MOTEUR.hpp"
using namespace MOTEUR;

/*
 * Getters
 */

string MOTEUR_QuitterProgramme::getActionId(){
    return "QuitterProgramme";
}
/*
 * Setters
 */
void MOTEUR_QuitterProgramme::setWindow(sf::RenderWindow* window){
    this->window=window;
}
/*
 * Methodes
 */

void MOTEUR_QuitterProgramme::apply(){
    std::cout<<"exit"<<std::endl;
}