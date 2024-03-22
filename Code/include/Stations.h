#ifndef STATIONS_H
#define STATIONS_H

#include <string>

using namespace std;

/// @class Station
/// @brief Stores the Information Regarding Pumping Stations
class Station {
public:
    /// @brief A Constructor for the Pumping Station
    /// @param station_id Integer with the Unique Identifier of the Pumping Station
    /// @param station_code String with the Code of the Pumping Station
    Station(int station_id, string station_code);

    /// @brief A Default Empty Constructor for the Pumping Station
    Station() = default;

    ///@brief A Function used to get the ID of a Pumping Station
    ///@return Returns the Integer of the ID of a Pumping Station
    int getStationId() const;

    ///@brief A Function used to get the Code of a Pumping Station
    ///@return Return the String of the Code of a Pumping Station
    string getStationCode() const;
private:
    /// @brief Id of Pumping Station
    int station_id_;

    /// @brief Code of Pumping Station
    string station_code_;
};
#endif //STATIONS_H
