#ifndef RENDU_JeuDeTuile_HPP
#define RENDU_JeuDeTuile_HPP

/* include ETAT */

#include "MAP_Carte.hpp"
#include "MAP_InventairePersonnage.hpp"
#include "MAP_Personnage.hpp"
#include "MAP_Coffre.hpp"
#include "MAP_ObjetInventaire.hpp"

#include "FIGHT_Personnage.hpp"
#include "FIGHT_Competence.hpp"
#include "FIGHT_Carte.hpp"

//#define NOMBRETUILES 50 (????) dans variableglobales

class RENDU_JeuDeTuile{
	private :
		RENDU_Tuile* listeTuile[50];
		int nombreTuiles;
		
	public:
		/*
		 * Constructeur 
		 */
		RENDU_JeuDeTuile();
		
		/*
		 * Destructeur 
		 */
		~RENDU_JeuDeTuile();
		
		/*
		 * Getters
		 */
		
		const char* const getImageFile();
		const RENDU_Tuile* const getElementTile(const MAP_Carte* carteMap);
		const RENDU_Tuile* const getElementTile(const MAP_Personnage* personnageMap);
		const RENDU_Tuile* const getElementTile(const MAP_Coffre* coffreMap);
		const RENDU_Tuile* const getElementTile(const MAP_InventairePersonnage* inventairePersonnageMap);
		const RENDU_Tuile* const getElementTile(const MAP_ObjetInventaire* objetInventaireMap);
		
		const RENDU_Tuile* const getElementTile(const FIGHT_Carte* carteFight);
		const RENDU_Tuile* const getElementTile(const FIGHT_Personnage* personnageFight);
		const RENDU_Tuile* const getElementTile(const FIGHT_Competence* competenceFight);
		
		int const getCellWidth(int i);
		int const getCellHeight(int i);
		const RENDU_Tuile* const getIntTile(int i);
		/*
		 * Setters
		 */
};
#endif
