#include "RENDU_Scene.hpp"

/* include état */

		/*int hauteur;
		int largeur;
		RENDU_Plan* plans;
		*/

/*
 * Constructeur 
 */
RENDU_Scene::RENDU_Scene(){
	RenderWindow window(VideoMode::getDesktopMode();
}

/*
 * Destructeur 
 */
~RENDU_Scene::RENDU_Scene(){
	
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
	//TODO
}

/*
 * Setters
 */
void RENDU_Scene::setLayer(int idx, RENDU_Plan* plans){
	//TODO
}
void RENDU_Scene::setSurface(int idx, RENDU_Surface* surface){
	//TODO
}

/*
 * Methodes
 */  
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
