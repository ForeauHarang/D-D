#ifndef MOTEUR_DEPLACEMENTPERSONNAGE_HPP
#define MOTEUR_DEPLACEMENTPERSONNAGE_HPP

#include "MOTEUR_Action.hpp"
#include "../MAP/MAP_Personnage.hpp"
#include <string>
using std::string;

class MOTEUR_DeplacementPersonnage : public MOTEUR_Action{

	protected:

		int dx;
		int dy;
		MAP_Personnage* ptrperso;
		
		
	public:
		/*
		 * Constructeur 
		 */
		MOTEUR_DeplacementPersonnage():MOTEUR_Action(){}
		MOTEUR_DeplacementPersonnage(int dx, int dy, MAP_Personnage* ptrperso):MOTEUR_Action(){
			this->dx=dx;
			this->dy=dy;
			this->ptrperso=ptrperso;
		}
		
		/*
		 * Destructeur 
		 */
		virtual ~MOTEUR_DeplacementPersonnage(){}
		
		/*
		 * Getters
		 */
		int getX();
		int getY();
		int getDX();
		int getDY();
		
		MAP_Personnage* getCharacterPtr();
		
		virtual string getActionId() override;
		/*
		 * Setters
		 */
		
		/*
		 * Methodes
		 */ 
		 
		 virtual void apply() override;
};
#endif
