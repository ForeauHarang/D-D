#ifndef RENDU_Tuile_HPP
#define RENDU_Tuile_HPP

class RENDU_Tuile {
	public :
		/*
		 * Constructeur 
		 */
		RENDU_Tuile();
		
		/*
		 * Destructeur 
		 */
		virtual ~RENDU_Tuile()=0;
		
		/*
		 * Methodes
		 */
		virtual int const getX()=0;
		virtual int const getY()=0;
		virtual int const getWidth()=0;
		virtual int const getHeight()=0;
		
		/*
		 * Setters
		 */
		virtual void setX(int x)=0; 
		virtual void setY(int y)=0;
		virtual void setWidth(int largeur)=0;
		virtual void setHeight(int hauteur)=0; 
		
		/*
		 * Methodes
		 */	 
		virtual bool const isAnimated()=0;
};
#endif

/*
* Tableau de Tuiles :
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