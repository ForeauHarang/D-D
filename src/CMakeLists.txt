cmake_minimum_required(VERSION 3.3)
project(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ETAT_EtatObserver.cpp
    ETAT_EtatObserver.hpp
    FIGHT_Carte.cpp
    FIGHT_Carte.hpp
    FIGHT_Competence.cpp
    FIGHT_Competence.hpp
    FIGHT_Personnage.cpp
    FIGHT_Personnage.hpp
    FIGHT_VariablesGlobales.hpp
    main.cpp
    MAP_Carte.cpp
    MAP_Carte.hpp
    MAP_Coffre.cpp
    MAP_Coffre.hpp
    MAP_InventairePersonnage.cpp
    MAP_InventairePersonnage.hpp
    MAP_ObjetInventaire.cpp
    MAP_ObjetInventaire.hpp
    MAP_Personnage.cpp
    MAP_Personnage.hpp
    MAP_Quete.cpp
    MAP_Quete.hpp
    MAP_VariablesGlobales.hpp
    RENDU_AnimatedTuile.cpp
    RENDU_AnimatedTuile.hpp
    RENDU_Animation.cpp
    RENDU_Animation.hpp
    RENDU_DebugPlan.cpp
    RENDU_DebugPlan.hpp
    RENDU_EtatPlan.cpp
    RENDU_EtatPlan.hpp
    RENDU_JeuDeTuile.cpp
    RENDU_JeuDeTuile.hpp
    RENDU_ListeElementPlan.cpp
    RENDU_ListeElementPlan.hpp
    RENDU_Plan.cpp
    RENDU_Plan.hpp
    RENDU_Scene.cpp
    RENDU_Scene.hpp
    RENDU_StaticTuile.cpp
    RENDU_StaticTuile.hpp
    RENDU_Surface.cpp
    RENDU_Surface.hpp
    RENDU_Tuile.cpp
    RENDU_Tuile.hpp
    RENDU_VariablesGlobales.hpp
    TileMap.cpp
    TileMap.hpp)
enable_language(CXX)
add_executable(src ${SOURCE_FILES})