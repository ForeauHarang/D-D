cmake_minimum_required (VERSION 2.6)
project (3a)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(EXECUTABLE_OUTPUT_PATH ../bin)
add_executable(
	vandw

	src/MAP_Personnage.hpp
	src/FIGHT_Carte.hpp
	src/MAP_Carte.hpp
	src/MAP_Coffre.hpp
	src/MAP_Quete.hpp
	src/MAP_ObjetInventaire.hpp
	src/MAP_InventairePersonnage.hpp
	src/FIGHT_Competence.hpp
	src/FIGHT_Personnage.hpp
	src/MAP_VariablesGlobales.hpp
	src/FIGHT_VariablesGlobales.hpp
	
	src/main.cpp
	src/MAP_Carte.cpp
	src/MAP_Coffre.cpp
	src/MAP_InventairePersonnage.cpp	
	src/MAP_ObjetInventaire.cpp	
	src/MAP_Quete.cpp	
	src/MAP_Personnage.cpp	
	src/FIGHT_Carte.cpp	
	src/FIGHT_Competence.cpp	
	src/FIGHT_Personnage.cpp

)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_module" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(vandw ${SFML_LIBRARIES})
endif()
