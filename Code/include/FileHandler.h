#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <locale>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Reservoirs.h"
#include "Stations.h"
#include "Cities.h"
#include "Pipes.h"
#include "Graph.h"

using namespace std;

///@class FileHandler
///@brief Class used for the handling of the datasets, i.e., connecting the dataset with the program
class FileHandler {
public:
    ///@brief A Function used to read the Reservoirs CSV
    void readReservoirs();

    ///@brief A Function that when a line in CSV is read, Update the Reservoirs Vector by Adding the new Line
    void parseReservoir(string currLine);

    ///@brief A Function used get the vector with all Reservoirs
    ///@return Returns the Vector Containing all the Reservoirs
    vector<Reservoir> getReservoirsVector();

    ///@brief A Function used to read the Stations CSV
    void readStations();

    ///@brief A Function that when a line in CSV is read, Update the Stations Vector by Adding the new Line
    void parseStation(string currLine);

    ///@brief A Function used get the vector with all Stations
    ///@return Returns the Vector Containing all the Stations
    vector<Station> getStationsVector();

    ///@brief A Function used to read the Cities CSV
    void readCities();

    ///@brief A Function that when a line in CSV is read, Update the Cities Vector by Adding the new Line
    void parseCity(string currLine);

    ///@brief A Function used get the vector with all Cities
    ///@return Returns the Vector Containing all the Cities
    vector<City> getCitiesVector();

    ///@brief A Function used to read the Pipes CSV
    void readPipes();

    ///@brief A Function that when a line in CSV is read, Update the Pipes Vector by Adding the new Line
    void parsePipe(string currLine);

    ///@brief A Function used get the vector with all Pipes
    ///@return Returns the Vector Containing all the Pipelines
    vector<Pipe> getPipesVector();

    ///@brief A Function used get the Graph with all Reservoirs, Cities, Stations and Pipes
    ///@return Returns the Graph Containing all information
    Graph * getGraph();

private:
    ///@brief Vector with the Water Reservoirs
    vector<Reservoir> reservoirs_;

    ///@brief Vector with the Pumping Stations
    vector<Station> stations_;

    ///@brief Vector with the Cities (Delivery Sites)
    vector<City> cities_;

    ///@brief Vector with the Pipelines Connecting Cities, Reservoirs and Stations
    vector<Pipe> pipes_;

};



#endif //FILEHANDLER_H
