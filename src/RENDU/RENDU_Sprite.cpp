#include "RENDU.hpp"
/*
class RENDU_Sprite : public RENDU_Sprite{
private :
	std::string ElementString;
	int X;
	int Y;
	int DirectionX;
	int DirectionY;
	std::string stringId;
*/

using namespace MAP;
using namespace RENDU;

/*
* Constructeurs
*/
RENDU_Sprite::RENDU_Sprite(std::string path, std::string id, MAP_Personnage* personnagePtr) {
	this->stringId = id;
	this->elementString = path;
	this->personnagePtr = personnagePtr;
}

/*
* Getters 
*/
std::string RENDU_Sprite::getElementString(){
	return this->elementString;
}

int RENDU_Sprite::getX(){
	return this->X;
}

int RENDU_Sprite::getY(){
	return this->Y;
}

int RENDU_Sprite::getDirectionX(){
	return this->DirectionX;
}

int RENDU_Sprite::getDirectionY(){
	return this->DirectionY;
}

std::string RENDU_Sprite::getElemId(){
	return this->stringId;
}

MAP_Personnage* RENDU_Sprite::getCharacterPtr(){
	return this->personnagePtr;
}

/*
* Setters
*/
void RENDU_Sprite::setElementString(std::string path){
	this->elementString=path;
}

void RENDU_Sprite::setX(int X){
	this->Y=Y;
}

void RENDU_Sprite::setY(int Y){
	this->Y=Y;
}

void RENDU_Sprite::setDirectionX(int dirX){
	this->DirectionX=dirX;
}

void RENDU_Sprite::setDirectionY(int dirY){
	this->DirectionY=dirY;
}

void RENDU_Sprite::setElementId(std::string stringId){
	this->stringId=stringId;
}

/*
* Methodes
*/
void RENDU_Sprite::draw(sf::RenderTarget&, sf::RenderStates) const{

}

bool RENDU_Sprite::load() {
	return false;
}

