#include "RENDU_Scene.hpp"

/* include état */

		/*int hauteur;
		int largeur;
		RENDU_Plan* plans;
		* fenetre
		*/
		sf::RenderWindow window;

/*
 * Constructeur 
 */
RENDU_Scene::RENDU_Scene(){
	sf::RenderWindow window(sf::VideoMode(800,600), "W&V");
	this->hauteur = 800;
	this->largeur = 600;
	/*
	ScreenR = VideoMode::getDesktopMode().width;
	ScreenB = VideoMode::getDesktopMode().height;
	 * 
	 * 
	 * */
}

/*
 * Destructeur 
 */
RENDU_Scene::~RENDU_Scene(){
	
}

/*
 * Getters
 */
int const RENDU_Scene::getWidth(){
	return this->largeur;
}
int const RENDU_Scene::getHeight(){
	return this->hauteur;
}
int const RENDU_Scene::getLayerCount(){
	return 1;
}
/*
sf::Window RENDU_Scene::getWindow(){
	return this->fenetre;
}
* */
/*
 * Setters
 */
 /*
void RENDU_Scene::setLayer(int idx, RENDU_Plan* plans){
	//TODO
}
void RENDU_Scene::setSurface(int idx, RENDU_Surface* surface){
	//TODO
}
*/
/*
 * Methodes
 */ 
 /*
void RENDU_Scene::registerObservers(const ETAT::ETAT* s){
	//TODO
}
void RENDU_Scene::unregisterObservers(const ETAT::ETAT* s){
	//TODO
}
void RENDU_Scene::stateChanged(const ETAT::ETATEvent& e){
	//TODO
}
void RENDU_Scene::sync(int64_t temps){
	//TODO
}
void RENDU_Scene::update(int64_t temps){
	//TODO
}
*/
