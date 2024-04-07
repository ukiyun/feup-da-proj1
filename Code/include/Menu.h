#ifndef MENU_H
#define MENU_H

#include <locale>
#include "fileHandler.h"
#include "Cities.h"
#include "Stations.h"
#include "Reservoirs.h"
#include "Pipes.h"
#include "Graph.h"
#include "Utils.h"

/// @class Menu
/// @brief  A Class Dedicated to the Program's Interface
class Menu {
public:
    /// @brief Main Function to Open the Program
    void open();
private:
    /// @brief Function used to Display the Program's Main Menu
    bool displayMainMenu();

    // ============ Reservoir Functions ============== //
    /// @brief Program Option to show a menu with basic functions available for the Reservoirs
    void reservoirFunctions();

    /// @brief Function to print all Reservoirs
    void printReservoirs();

    /// @brief Function to find and print a reservoir by ID
    void findReservoirsById();

    /// @brief Function to find and print Reservoirs by Municipality
    void findReservoirsByMunicipality();

    /// @brief Function to get Reservoir with highest and lowest Delivery
    void getReservoirMaxMinDelivery();


    // ============ Station Functions ============== //
    /// @brief Program Option to show a menu with basic functions available for the Stations
    void stationFunctions();

    /// @brief Function to print all Stations
    void printStations();

    /// @brief Function to find and print a Station by ID
    void findStationsById();

    // ============ City Functions ============== //
    /// @brief Program Option to show a menu with basic functions available for the Cities
    void cityFunctions();

    /// @brief Function to print all Cities
    void printCities();

    /// @brief Function to find and print a City by ID
    void findCityById();

    /// @brief Function to get City with highest and lowest Demand
    void getCityMaxMinDemand();

    /// @brief Function to get City with highest and lowest Population
    void getCityMaxMinPopulation();

    // ============ Pipe Functions ============== //
    /// @brief Program Option to show a menu with basic functions available for the Pipes
    void pipeFunctions();

    /// @brief Function to print all Pipes
    void printPipes();

    /// @brief Function to get Pipe with highest and lowest Capacity
    void getPipesMaxMinCapacity();

    // ============ Other Functions ============== //
    /// @brief Program Option to Determine Max Water Flow
    void determineMaxWaterFlow();

    /// @brief Program Option to Check the Water Needs
    void verifyWaterNeeds();

    /// @brief Program Option to Check the Balance Load
    void balanceLoad();

    /// @brief Program Option to Analise Resilience
    void resilienceAnalysis();

    /// @brief Program Option to Analise Pipeline Failure
    void pipelineFailureAnalysis();

    FileHandler loadedFiles;
    string type_;
};

#endif //MENU_H
