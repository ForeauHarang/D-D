cmake_minimum_required (VERSION 2.6)
project (3a)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(EXECUTABLE_OUTPUT_PATH ../bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lsfml-graphics -lsfml-window -lsfml-system")
add_executable(
	vandw
		
	
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
	
#	src/RENDU/RENDU_AnimatedTuile.hpp
#	src/RENDU/RENDU_Animation.hpp
#	src/RENDU/RENDU_DebugPlan.hpp
#	src/RENDU/RENDU_EtatPlan.hpp
	src/RENDU/RENDU_JeuDeTuile.hpp
#	src/RENDU/RENDU_ListeElementPlan.hpp
#	src/RENDU/RENDU_Plan.hpp
#	src/RENDU/RENDU_Scene.hpp
	src/RENDU/RENDU_StaticTuile.hpp
#	src/RENDU/RENDU_Surface.hpp
	src/RENDU/RENDU_Tuile.hpp
	src/RENDU/RENDU_VariablesGlobales.hpp	
	
#	src/ETAT/ETAT_EtatObserver.hpp
	
	src/MOTEUR/MOTEUR_Action.hpp
	src/MOTEUR/MOTEUR_DeplacementPersonnage.hpp
	src/MOTEUR/MOTEUR_ListeAction.hpp
	src/MOTEUR/MOTEUR_Regle.hpp
	
	src/RENDU/RENDU_Fenetre.hpp
	src/RENDU/RENDU_ElementGraphique.hpp
	src/RENDU/RENDU_Sprite.hpp
	src/RENDU/TileMapnew.hpp
	
	src/RENDU/TileMap.hpp
	
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
	
#	src/RENDU/RENDU_AnimatedTuile.cpp
#	src/RENDU/RENDU_Animation.cpp
#	src/RENDU/RENDU_DebugPlan.cpp
#	src/RENDU/RENDU_EtatPlan.cpp
	src/RENDU/RENDU_JeuDeTuile.cpp
#	src/RENDU/RENDU_ListeElementPlan.cpp
#	src/RENDU/RENDU_Plan.cpp
#	src/RENDU/RENDU_Scene.cpp
	src/RENDU/RENDU_StaticTuile.cpp
#	src/RENDU/RENDU_Surface.cpp
	src/RENDU/RENDU_Tuile.cpp
	src/RENDU/RENDU_Fenetre.cpp
	src/RENDU/RENDU_ElementGraphique.cpp
	src/RENDU/TileMapnew.cpp
	src/RENDU/RENDU_Sprite.cpp
	
	src/RENDU/TileMap.cpp
	
#	src/ETAT/ETAT_EtatObserver.cpp

	src/MOTEUR/MOTEUR_Action.cpp
	src/MOTEUR/MOTEUR_DeplacementPersonnage.cpp
	src/MOTEUR/MOTEUR_ListeAction.cpp
	src/MOTEUR/MOTEUR_Regle.cpp
	
	src/IHM/IHM_PersonnageControleur.cpp
	src/IHM/IHM_PersonnageControleur.hpp

)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_module" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(vandw ${SFML_LIBRARIES})
endif()


