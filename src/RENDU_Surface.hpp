#ifndef RENDU_Surface_HPP
#define RENDU_Surface_HPP

#include "RENDU_VariablesGlobales.hpp"

class RENDU_Surface{
		
	public:
		/*
		 * Constructeur 
		 */
		RENDU_Surface();
		
		/*
		 * Destructeur 
		 */
		~RENDU_Surface();
 
		
		/*
		 * Methodes
		 */  
		void clear(sf::Window window);// nettoie une fenetre
		void loadTexture(const char* imageFile);
		
		/*
		 * Setters
		 */
		void setSpriteCount(int n);
		void setSpriteLocation(int x, int y, int i);
		void setSpriteTexture(int i, const RENDU_StaticTuile* tex);
		
};
#endif

/*
 * class Bloc {

	std::string file;
	Vector2u size;

	protected :
		sf::Sprite sprite;
		sf::Texture texture;

	public :
		Bloc();
		Bloc(std::string file);
		~Bloc();

	std::string getFile();
	sf::Texture getTexture();
	sf::Sprite getSprite();
	sf::Vector2u getSize();
	sf::Vector2f getPosition();
	void setFile(std::string file);
	void setTexture(sf::Texture texture);
	void setSprite(sf::Sprite sprite);
	void setSize(sf::Vector2u size);
	void setSize(float x, float y);
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);

	};

Bloc::Bloc(){
	file = "";
	size = Vector2u(32,32);
	};

Bloc::Bloc(std::string file){
			this->file = file;
			texture.loadFromFile(file);
			if(!texture.loadFromFile(file))
			{
				std::cout << "erreur chargement fichier.png" << std::endl;
			}
			sprite.setTexture(texture);
			size = texture.getSize();
	};

Bloc::~Bloc(){};

std::string Bloc::getFile(){
	return file;}
	
Texture Bloc::getTexture(){
	return texture;}
	
Sprite Bloc::getSprite(){
	return sprite;}
	
Vector2u Bloc::getSize(){
	return size;}

Vector2f Bloc::getPosition(){
	return sprite.getPosition();}

void Bloc::setFile(std::string file){
	this->file = file;}
	
void Bloc::setTexture(Texture texture){
	this->texture = texture;}
	
void Bloc::setSprite(Sprite sprite){
	this->sprite = sprite;}
	
void Bloc::setSize(Vector2u size){
	this->size = size;}
	
void Bloc::setSize(float x, float y){
	this->size = Vector2u(x,y);}

void Bloc::setPosition(Vector2f position){
	sprite.setPosition(position);}
	
void Bloc::setPosition(float x, float y){
	sprite.setPosition(x,y);}
*/
