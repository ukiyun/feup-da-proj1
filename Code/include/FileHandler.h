#ifndef FILEHANDLER_H
#define FILEHANDLER_H

/*
All datasets:
- Reservoirs (Reservoir, Municipality, ReservoirId, ReservoirCode, MaxDelievery)
- Pumping Stations (StationId, StationCode)
- Delivery Sites (City, CityId, CityCode, Demand, Population)
- Pipelines (ServicePointA, ServicePointB, Capacity, Direction)
*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

class fileHandler {

public:
    void readReservoirs();      // read Reservoirs.csv
    void loadReservoirs();
    // missing function to get vector with all Reservoirs

    void readStations();        // read Stations.csv
    void loadStations();
    // missing function to get vector with all Stations

    void readCities();          // read Cities.csv
    void loadCities();
    // missing function to get vector with all Delivery Sites

    void readPipes();           // read Pipes.csv
    void loadPipes();
    // missing function to get vector with all Pipelines
};



#endif //FILEHANDLER_H
