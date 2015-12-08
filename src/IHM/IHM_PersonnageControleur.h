#ifndef IHM_PERSONNAGECONTROLEUR__H
#define IHM_PERSONNAGECONTROLEUR__H

/// class IHM_PersonnageControleur - 
class IHM_PersonnageControleur {
  // Attributes
private:
  sf::Event  event;
  MOTEUR_ListeAction* actions;
  MAP_Carte* map;
  // Operations
public:
  IHM_PersonnageControleur (MAP_Carte* map, MOTEUR_ListeAction* actions);
  ~IHM_PersonnageControleur ();
  void  deplacementCommande (sf::Event event);
  void  fermerFenetre (sf::Event event, sf::RenderWindow* window);
};

#endif
