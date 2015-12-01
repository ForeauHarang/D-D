#include "RENDU_JeuDeTuile.hpp"

/* include ETAT */

/*
 * Constructeur 
 */
RENDU_JeuDeTuile::RENDU_JeuDeTuile(){
	//Pour les personnages, on prend celui de face (1er ligne, 2e colonne)
	listeTuile[0]= new RENDU_StaticTuile(0,0,32,32); // humain1 
	listeTuile[1]= new RENDU_StaticTuile(121,0,32,32); // humain2
	listeTuile[2]= new RENDU_StaticTuile(214,0,32,32); // loup_garou
	listeTuile[3]= new RENDU_StaticTuile(309,0,32,32); // monstre
	listeTuile[4]= new RENDU_StaticTuile(401,0,32,32); // guerrier
	listeTuile[5]= new RENDU_StaticTuile(497,0,32,32); // sorcier
	listeTuile[6]= new RENDU_StaticTuile(590,0,32,32); // vampire
	listeTuile[7]= new RENDU_StaticTuile(689,0,32,32); // voleur
	listeTuile[8]= new RENDU_StaticTuile(1,144,28,27); // boule_de_feu_1
	listeTuile[9]= new RENDU_StaticTuile(47,137,36,37); // poulet
	listeTuile[10]= new RENDU_StaticTuile(88,133,44,34); // coffre
	listeTuile[11]= new RENDU_StaticTuile(159,135,39,33); // montagne
	listeTuile[12]= new RENDU_StaticTuile(204,135,41,30); // herbe
	listeTuile[13]= new RENDU_StaticTuile(258,136,36,45); // livre
	listeTuile[14]= new RENDU_StaticTuile(313,136,59,35); // poignard
	listeTuile[15]= new RENDU_StaticTuile(392,133,52,42); // sable
	listeTuile[16]= new RENDU_StaticTuile(458,135,38,40); // roche
	listeTuile[17]= new RENDU_StaticTuile(507,140,64,31); // fusil
	listeTuile[18]= new RENDU_StaticTuile(585,138,49,40); // balle_argent
	listeTuile[19]= new RENDU_StaticTuile(651,135,48,51); // bouclier
	listeTuile[20]= new RENDU_StaticTuile(707,134,46,57); // poche_de_sang
	listeTuile[21]= new RENDU_StaticTuile(2,185,30,27); // boule_de_feu_2
	listeTuile[22]= new RENDU_StaticTuile(57,190,76,50); // route
	listeTuile[23]= new RENDU_StaticTuile(156,174,41,72); // chemin
	listeTuile[24]= new RENDU_StaticTuile(204,185,46,62); // arbre
	listeTuile[25]= new RENDU_StaticTuile(257,187,52,45); // pistolet
	listeTuile[26]= new RENDU_StaticTuile(329,180,27,52); // potion_rose
	listeTuile[27]= new RENDU_StaticTuile(371,135,31,49); // potion_rouge
	listeTuile[28]= new RENDU_StaticTuile(411,180,32,51); // potion_jaune
	listeTuile[29]= new RENDU_StaticTuile(451,178,32,53); // potion_verte
	listeTuile[30]= new RENDU_StaticTuile(488,179,30,50); // potion_bleue
	listeTuile[31]= new RENDU_StaticTuile(535,184,56,40); // pieu
	listeTuile[32]= new RENDU_StaticTuile(609,200,33,36); // vetement
	listeTuile[33]= new RENDU_StaticTuile(668,200,33,36); // griffe
	listeTuile[34]= new RENDU_StaticTuile(2,235,31,31); // boule_de_feu_3
	listeTuile[35]= new RENDU_StaticTuile(274,237,36,29); // morsure
	listeTuile[36]= new RENDU_StaticTuile(232,238,34,34); // kevlar
	listeTuile[37]= new RENDU_StaticTuile(0,277,847,616); // carte_MAP
	listeTuile[38]= new RENDU_StaticTuile(0,905,842,522); // carte_FIGHT
	listeTuile[39]= new RENDU_StaticTuile(6,1443,466,372); // inventaire
	listeTuile[40]= new RENDU_StaticTuile(500,1455,1,1); // pixel_blanc
}

/*
 * Destructeur 
 */
RENDU_JeuDeTuile::~RENDU_JeuDeTuile(){
	delete[] listeTuile[NOMBRETUILES];
}

/*
 * Getters
 */
 
const char* const RENDU_JeuDeTuile::getImageFile(){
	return "../res/images/IMAGE.JPEG";
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile(MAP_Carte carteMap){
	return this->listeTuile[37];
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( MAP_Personnage personnageMap){
	//enum Race { HUMAIN, LOUP_GAROU, VAMPIRE, MONSTRE };
	
	if(personnageMap.getRace()==HUMAIN) return this->listeTuile[0];
	if(personnageMap.getRace()==LOUP_GAROU) return this->listeTuile[2];
	if(personnageMap.getRace()==VAMPIRE) return this->listeTuile[6];
	if(personnageMap.getRace()==MONSTRE) return this->listeTuile[3];
	
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( MAP_Coffre coffreMap){
	return this->listeTuile[10];
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( MAP_InventairePersonnage inventairePersonnageMap){
	return this->listeTuile[39]; // a mettre
}
const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( MAP_ObjetInventaire objetInventaireMap){
//	enum NomObjet {PASDENOM, COUTEAU, PISTOLET, FUSIL, VETEMENT, KELVAR, POTION_SOIN,
//		 POTION_MANA, POISON, LIVRE, POULET, BALLES_ARGENTS, SAC_SANG, PIEUX };
	if(objetInventaireMap.getItemName()==PASDENOM) return this->listeTuile[40];
	if(objetInventaireMap.getItemName()==COUTEAU) return this->listeTuile[14];
	if(objetInventaireMap.getItemName()==PISTOLET) return this->listeTuile[25];
	if(objetInventaireMap.getItemName()==FUSIL) return this->listeTuile[17];
	if(objetInventaireMap.getItemName()==VETEMENT) return this->listeTuile[32];//
	if(objetInventaireMap.getItemName()==KELVAR) return this->listeTuile[36];//
	if(objetInventaireMap.getItemName()==POTION_SOIN) return this->listeTuile[27];
	if(objetInventaireMap.getItemName()==POTION_MANA) return this->listeTuile[30];
	if(objetInventaireMap.getItemName()==POISON) return this->listeTuile[29];
	if(objetInventaireMap.getItemName()==LIVRE) return this->listeTuile[13];
	if(objetInventaireMap.getItemName()==POULET) return this->listeTuile[9];
	if(objetInventaireMap.getItemName()==BALLES_ARGENTS) return this->listeTuile[18];
	if(objetInventaireMap.getItemName()==SAC_SANG) return this->listeTuile[20];
	if(objetInventaireMap.getItemName()==PIEUX) return this->listeTuile[31];

}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( FIGHT_Carte carteFight){
	return this->listeTuile[38];
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( FIGHT_Personnage personnageFight){
//enum FIGHT_Race { FIGHT_HUMAIN, FIGHT_LOUP_GAROU, FIGHT_VAMPIRE, FIGHT_MONSTRE };		
	if(personnageFight.getRace()==FIGHT_HUMAIN) return this->listeTuile[0];
	if(personnageFight.getRace()==FIGHT_LOUP_GAROU) return this->listeTuile[2];
	if(personnageFight.getRace()==FIGHT_VAMPIRE) return this->listeTuile[6];
	if(personnageFight.getRace()==FIGHT_MONSTRE) return this->listeTuile[3];
	
}

const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile( FIGHT_Competence competenceFight){
	if(competenceFight.getSkillName()==FIGHT_ATTAQUER) return this->listeTuile[14];
	if(competenceFight.getSkillName()==FIGHT_BOULEDEFEU) return this->listeTuile[34];
	if(competenceFight.getSkillName()==FIGHT_MORSURE) return this->listeTuile[35];
	if(competenceFight.getSkillName()==FIGHT_GRIFFE) return this->listeTuile[33];
	if(competenceFight.getSkillName()==FIGHT_BOUCLIER) return this->listeTuile[19];
	if(competenceFight.getSkillName()==FIGHT_POTION) return this->listeTuile[28];
}
//enum FIGHT_NomCompetence {  FIGHT_ATTAQUER,  FIGHT_BOULEDEFEU,  FIGHT_MORSURE,  FIGHT_GRIFFE,  FIGHT_BOUCLIER,  FIGHT_POTION };

int const RENDU_JeuDeTuile::getCellWidth(int i){
	return (*this->listeTuile[i]).getWidth();
}

int const RENDU_JeuDeTuile::getCellHeight(int i){
	return (*this->listeTuile[i]).getHeight();
}

/*
const RENDU_Tuile* const RENDU_JeuDeTuile::getElementTile(const ETAT::Element* e){
	//TODO
}
*/
const RENDU_Tuile* const RENDU_JeuDeTuile::getIntTile(int i){
	return this->listeTuile[i];
}


