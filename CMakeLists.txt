cmake_minimum_required (VERSION 2.6)
project (3a)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(EXECUTABLE_OUTPUT_PATH ../bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lsfml-graphics -lsfml-window -lsfml-system")
add_executable(
		vandw

		#HPP
		src/MAP/MAP_Personnage.hpp
		src/MAP/MAP_Carte.hpp
		src/MAP/MAP_Coffre.hpp
		src/MAP/MAP_Quete.hpp
		src/MAP/MAP_ObjetInventaire.hpp
		src/MAP/MAP_InventairePersonnage.hpp
		src/MAP/MAP_VariablesGlobales.hpp

		src/FIGHT/FIGHT_Carte.hpp
		src/FIGHT/FIGHT_Competence.hpp
		src/FIGHT/FIGHT_Personnage.hpp
		src/FIGHT/FIGHT_VariablesGlobales.hpp

#		src/FIGHT/FIGHT.hpp

		src/RENDU/RENDU_VariablesGlobales.hpp
		src/RENDU/RENDU_Fenetre.hpp
		src/RENDU/RENDU_ElementGraphique.hpp
		src/RENDU/RENDU_Sprite.hpp
		src/RENDU/TileMapnew.hpp

		#src/RENDU/TileMap.hpp

		src/MOTEUR/MOTEUR_Action.hpp
		src/MOTEUR/MOTEUR_DeplacementPersonnage.hpp
		src/MOTEUR/MOTEUR_ListeAction.hpp
		src/MOTEUR/MOTEUR_Regle.hpp
		src/MOTEUR/MOTEUR_QuitterProgramme.hpp

		src/IHM/IHM_PersonnageControleur.hpp

		src/IA/IA_IASimple.hpp
		src/IA/IA_DeplacementCase.hpp
		src/IA/IA_ComplexeDeplacement.hpp

		#CPP
		src/main.cpp

		src/MAP/MAP_Carte.cpp
		src/MAP/MAP_Coffre.cpp
		src/MAP/MAP_InventairePersonnage.cpp
		src/MAP/MAP_ObjetInventaire.cpp
		src/MAP/MAP_Quete.cpp
		src/MAP/MAP_Personnage.cpp

		src/FIGHT/FIGHT_Carte.cpp
		src/FIGHT/FIGHT_Competence.cpp
		src/FIGHT/FIGHT_Personnage.cpp

		src/RENDU/RENDU_Fenetre.cpp
		src/RENDU/RENDU_ElementGraphique.cpp
		src/RENDU/TileMapnew.cpp
		src/RENDU/RENDU_Sprite.cpp

		#src/RENDU/TileMap.cpp

		src/MOTEUR/MOTEUR_Action.cpp
		src/MOTEUR/MOTEUR_DeplacementPersonnage.cpp
		src/MOTEUR/MOTEUR_ListeAction.cpp
		src/MOTEUR/MOTEUR_Regle.cpp
		src/MOTEUR/MOTEUR_QuitterProgramme.cpp

		src/IHM/IHM_PersonnageControleur.cpp

		src/IA/IA_IASimple.cpp
		src/IA/IA_DeplacementCase.cpp
		src/IA/IA_ComplexeDeplacement.cpp

# MOTEUR de jeu
	#src/MOTEUR_ModeCommande.cpp
	#src/MOTEUR_ModeCommande.hpp
	#src/MOTEUR_ChargementCommande.cpp
	#src/MOTEUR_ChargementCommande.hpp
	#src/MOTEUR_DirectionCommande.cpp
	#src/MOTEUR_DirectionCommande.hpp
	#src/MOTEUR_Commande.cpp
	#src/MOTEUR_Commande.hpp
	
	#src/MOTEUR_VariablesGlobales.hpp

		src/MOTEUR/MOTEUR.hpp src/MOTEUR/MOTEUR_QuitterProgramme.cpp src/MOTEUR/MOTEUR_QuitterProgramme.hpp)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_module" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(vandw ${SFML_LIBRARIES})
endif()


