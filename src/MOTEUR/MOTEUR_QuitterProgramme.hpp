//
// Created by gabriel on 08/12/15.
//

#ifndef INC_3A_MOTEUR_QUITTERPROGRAMME_HPP
#define INC_3A_MOTEUR_QUITTERPROGRAMME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MOTEUR_Action.hpp"
#include <iostream>


class MOTEUR_QuitterProgramme : public MOTEUR_Action{

    protected:
        sf::RenderWindow* window;

    public:
        /*
         * Constructeur
         */
        MOTEUR_QuitterProgramme():MOTEUR_Action(){}


        /*
         * Destructeur
         */
        virtual ~MOTEUR_QuitterProgramme(){}

        /*
         * Getters
         */

        virtual string getActionId() override;
        /*
         * Setters
         */
        void setWindow(sf::RenderWindow* window);
        /*
         * Methodes
         */

        virtual void apply() override;
};


#endif //INC_3A_MOTEUR_QUITTERPROGRAMME_HPP
