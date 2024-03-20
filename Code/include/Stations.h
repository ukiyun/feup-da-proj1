#ifndef STATIONS_H
#define STATIONS_H

#include <string>

using namespace std;

class Stations {
public:

    Stations(int station_id, string station_code);  // Constructor
    Stations() = default;                   // Default Constructor
    int getStationId() const;               // Return the station id
    string getStationCode() const;          // Return the station code
private:
    int station_id_;
    string station_code_;
};
#endif //STATIONS_H
