cmake_minimum_required(VERSION 3.10)
# set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_MESSAGE_LOG_LEVEL VERBOSE)
include(cmake_cours.cmake)  # Certaines fonctions de configuration de compilation pour ce cours.

# Le nom du projet.
project(ProjetTest CXX)

afficher_infos_generateur()  # Doit être après "project( )".

set(BILIOTHEQUE_COURS
	"bibliotheque_cours/bibliotheque_cours.cpp"
	"include/bibliotheque_cours.hpp"
	"include/CodeCoverage_bugfix.h"
	"bibliotheque_cours/verification_allocation.cpp"
	"include/verification_allocation.hpp"
	"include/debogage_memoire.hpp"
)

# On met les fichiers sources (incluant les entêtes)
file(GLOB ALL_FILES
	*.cpp
	*.hpp
	*.h
	*.ui
	${BILIOTHEQUE_COURS}
)

configurer_options_compilation_globales()  # Doit être avant le "add_executable".
configurer_Qt_auto_tout()                  # Doit être avant le "add_executable".
add_executable(${PROJECT_NAME} ${ALL_FILES})

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)  # Mettre ici ce qui est requis de Qt (et mettre Qt5 ou Qt6 selon la version que vous avez).
afficher_version_Qt()  # Doit être après le "find_package(Qt...".
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)  # Doit être après le "add_executable" et lui passer le même nom.  Mettre encore ici ce qui est requis de Qt.
configurer_GoogleTest(${PROJECT_NAME})  # Doit être après le "add_executable" et lui passer le même nom.

ajouter_target_couverture(${PROJECT_NAME})  # Doit être après le "add_executable" et lui passer le même nom. Ajoute un cible ${PROJECT_NAME}_couverture pour obtenir la couverture de code avec gcov (si on trouve gcov).

# On ajoute le dossier include/ fourni, comme des fichiers d'inclusion du système.
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE "include")


# Tous les package Vcpkg. Pour savoir quoi mettre, on fait "vcpkg install <le package>", puis on met ce qu'ils disent de mettre dans le CMakeLists.
# find_package(cppitertools CONFIG REQUIRED)  # On pourrait prendre le cppitertools de vcpkg au lieu de celui fourni dans include/
# find_package(Microsoft.GSL CONFIG  REQUIRED)  # Et GSL, noter que son nom de package est "ms-gsl" (le package "gsl" dans vcpkg est le "GNU Scientific Library" et non le "Guidelines Support Library").
