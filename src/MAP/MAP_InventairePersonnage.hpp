#ifndef MAP_INVENTAIREPERSONNAGE_HPP
#define MAP_INVENTAIREPERSONNAGE_HPP

#include "MAP_VariablesGlobales.hpp"
#include "MAP_ObjetInventaire.hpp"
#include <iostream>

/* changer l'uml état MAP*/

class MAP_InventairePersonnage{
	private :
		MAP_ObjetInventaire *tableauSlots[NOMBRESLOTS]; /* cf fin de header */
/*		MAP_ObjetInventaire slotTemporaire; */
		bool inventaireOuvert;
	
	public :
	
		/*
		* constructeurs
		* */
		
		MAP_InventairePersonnage();
		MAP_InventairePersonnage(MAP_ObjetInventaire* tableauSlots[NOMBRESLOTS]);
		
		/*
		* destructeurs
		* */
		
		~MAP_InventairePersonnage();
		
		/*
		* getteurs
		* */
		
		MAP_ObjetInventaire getItemInSlot(int numeroSlot);
		bool isInventoryOpen();
		
		/*
		* setteurs
		* */
		
		void moveItemToSlot(int numeroSlot, int origine);
		void addItemInBag(TypeObjet, NomObjet);
		void closeInventory();
		void openInventory();
		
		/*
		* autres méthodes
		* */
		
		bool isSlotFree(int numeroSlot);
		bool isSlotOK(MAP_ObjetInventaire objetInventaire, int numeroSlot);
		
		
						
};

#endif

/* tableaSlot
tableaSlot[0]  : transition
tableaSlot[1]  : garbage
tableaSlot[2]  : arme
tableaSlot[3]  : armure
tableaSlot[4]  : potion
tableaSlot[5]  : misc
tableaSlot[6]  : misc
tableaSlot[7]  : misc
tableaSlot[8]  : misc
tableaSlot[9]  : misc
tableaSlot[10] : misc
tableaSlot[11] : misc
tableaSlot[12] : misc
tableaSlot[13] : misc
tableaSlot[14] : misc
*/

