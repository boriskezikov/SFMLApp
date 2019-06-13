cmake_minimum_required(VERSION 3.13)
project(SFMLApp)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/Users/kezikovboris/Downloads/SFML-2.5.1-macos-clangs/include")
set(SFML_LIBRARY_DIR "/Users/kezikovboris/Downloads/SFML-2.5.1-macos-clangs/lib")
set(SFML_DIR "/Users/kezikovboris/Downloads/SFML-2.5.1-macos-clangs/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(SFMLApp
        images/Animal.png
        images/Baby.png
        images/Branch.png
        images/Cleaner.png
        images/collectorBranch.png
        images/collectorFood.png
        images/Enemy.png
        images/Food.png
        images/Grass.png
        images/Litter.png
        images/Nanny.png
        images/Sand.png
        images/Shepherd.png
        images/Warrior.png
        Ant.cpp
        Ant.h
        Anthill.h
        Baby.h
        Cleaner.h
        Collector.h
        Enemy.cpp
        Enemy.h
        Engine.cpp
        Engine.h
        Field.cpp
        Field.h
        Informer.cpp
        Informer.h
        Nanny.h
        Role.h
        Shepherd.h
        main.cpp
        main.h
        Warrior.h)
target_link_libraries (SFMLApp sfml-graphics sfml-window sfml-system)