#ifndef IA_MANAGER_HPP
#define IA_MANAGER_HPP

#include "../MOTEUR/MOTEUR_ListeAction.hpp"
#include "../MAP/MAP_Carte.hpp"

class IA_Manager {
	private:
		MOTEUR_ListeAction* actions;
		MAP_Carte* map;

	public:
		void reachTarget(int x, int y);
};