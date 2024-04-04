cmake_minimum_required(VERSION 3.27)
project(DAProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        Code/include/Menu.h
        Code/src/Menu.cpp
        Code/include/FileHandler.h
        Code/src/FileHandler.cpp
        Code/include/Reservoirs.h
        Code/include/Stations.h
        Code/include/Cities.h
        Code/include/Pipes.h
        Code/src/Cities.cpp
        Code/src/Pipes.cpp
        Code/src/Reservoirs.cpp
        Code/src/Stations.cpp
        Code/src/Utils.cpp
        Code/include/Utils.h
        Code/src/Graph.cpp
        Code/include/Graph.h
)
