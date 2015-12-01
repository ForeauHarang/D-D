#ifndef RENDU_JeuDeTuile_HPP
#define RENDU_JeuDeTuile_HPP

/* include ETAT */
#include "RENDU_VariablesGlobales.hpp"
#include "../MAP/MAP_Carte.hpp"
#include "../MAP/MAP_InventairePersonnage.hpp"
#include "../MAP/MAP_Personnage.hpp"
#include "../MAP/MAP_Coffre.hpp"
#include "../MAP/MAP_ObjetInventaire.hpp"

#include "../FIGHT/FIGHT_Personnage.hpp"
#include "../FIGHT/FIGHT_Competence.hpp"
#include "../FIGHT/FIGHT_Carte.hpp"


#include "RENDU_Tuile.hpp"
#include "RENDU_StaticTuile.hpp"



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
		const RENDU_Tuile* const getElementTile( MAP_Carte carteMap);
		const RENDU_Tuile* const getElementTile( MAP_Personnage personnageMap);
		const RENDU_Tuile* const getElementTile( MAP_Coffre coffreMap);
		const RENDU_Tuile* const getElementTile( MAP_InventairePersonnage inventairePersonnageMap);
		const RENDU_Tuile* const getElementTile( MAP_ObjetInventaire objetInventaireMap);
		
		const RENDU_Tuile* const getElementTile( FIGHT_Carte carteFight);
		const RENDU_Tuile* const getElementTile( FIGHT_Personnage personnageFight);
		const RENDU_Tuile* const getElementTile( FIGHT_Competence competenceFight);
		
		int const getCellWidth(int i);
		int const getCellHeight(int i);
		const RENDU_Tuile* const getIntTile(int i);
		/*
		 * Setters
		 */
};
#endif

/* Tableau de Tuiles :
tabtuile[0] = humain1
tabtuile[1] = humain2
tabtuile[2] = loup_garou
tabtuile[3] = monstre
tabtuile[4] = guerrier
tabtuile[5] = sorcier
tabtuile[6] = vampire
tabtuile[7] = voleur
tabtuile[8] = boule_de_feu_1
tabtuile[9] = poulet
tabtuile[10] = coffre
tabtuile[11] = montagne
tabtuile[12] = herbe
tabtuile[13] = chemin
tabtuile[14] = herbe
tabtuile[15] = livre
tabtuile[16] = poignard 
tabtuile[17] = sable
tabtuile[18] = roche
tabtuile[19] = fusil
tabtuile[20] = balle_argent
tabtuile[21] = bouclier
tabtuile[22] = poche_de_sang
tabtuile[23] = boule_de_feu_2
tabtuile[24] = route
tabtuile[25] = chemin
tabtuile[26] = arbre
tabtuile[27] = pistolet
tabtuile[28] = potion_rose
tabtuile[29] = potion_rouge
tabtuile[30] = potion_jaune
tabtuile[31] = potion_verte
tabtuile[32] = potion_bleue
tabtuile[33] = pieu
tabtuile[34] = boule_de_feu_3
tabtuile[35] = carte_map
tabtuile[36] = carte_fight
*/