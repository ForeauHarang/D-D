#ifndef RENDU_SPRITE_HPP
#define RENDU_SPRITE_HPP


#include "RENDU_ElementGraphique.hpp"
#include "../MAP/MAP_Personnage.hpp"

class RENDU_Sprite : public RENDU_ElementGraphique{
	private :
		std::string elementString;
		int X;
		int Y;
		int DirectionX;
		int DirectionY;
		std::string stringId;
		MAP_Personnage* personnagePtr;
		
		
		
	public :
		RENDU_Sprite(std::string path, std::string id);
		
		virtual ~RENDU_Sprite(){}
		
		std::string getElementString();
		int getX();
		int getY();
		int getDirectionX();
		int getDirectionY();
		virtual std::string getElemId() override;
		MAP_Personnage* getCharacterPtr();
		
		void setElementString(std::string path);
		void setX(int X);
		void setY(int Y);
		void setDirectionX(int dirX);
		void setDirectionY(int dirY);
		void setElementId(std::string stringId);
};


#endif
