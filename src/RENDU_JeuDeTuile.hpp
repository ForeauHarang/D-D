#ifndef RENDU_JeuDeTuile_HPP
#define RENDU_JeuDeTuile_HPP

/* include ETAT */

class RENDU_JeuDeTuile{
		
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
		int const getCellWidth();
		int const getCellHeight();
		const char* const getImageFile();
		const RENDU_Tuile* const getElementTile(const ETAT::Element* e);
		const RENDU_Tuile* const getCharTile(char c);
};
#endif
