#ifndef CITIES_H
#define CITIES_H

#include <string>

using namespace std;

/// @class Cities
/// @brief Stores the Information Regarding Delivery Sites
class Cities {
public:
    /// @brief A Constructor for the Delivery Site
    /// @param city String with the Name of the City
    /// @param city_id Integer with the Unique Identifier of the Delivery Site
    /// @param city_code String with the Code of the Delivery Site
    /// @param demand Integer with the Rate Demand or Need of Delivery Site in m3/sec
    /// @param population Integer with the Total Population of the Delivery Site
    Cities(string city, int city_id, string city_code, int demand, int population);

    /// @brief A Default Empty Constructor for the Delivery Site
    Cities() = default;

    /// @brief A Function used to get the City of a Delivery Site
    /// @return Returns the City of a Delivery Site
    string getCity() const;

    /// @brief A Function used to get the ID of a Delivery Site
    /// @return Returns the ID of a Delivery Site
    int getCityId() const;

    /// @brief A Function used to get the Code of a Delivery Site
    /// @return Returns the Code of a Delivery Site
    string getCityCode() const;

    /// @brief A Function used to get the Demand of a Delivery Site
    /// @return Returns the Rate Demand or Need of Delivery Site
    int getDemand() const;

    /// @brief A Function used to get the Total Population of a Delivery Site
    /// @return Returns the Total Population of Delivery Site
    int getPopulation() const;
private:
    /// @brief City of Delievery Site
    string city_;

    /// @brief Id of Delivery Site
    int city_id_;

    /// @brief Code of Delievery Site
    string city_code_;

    /// @brief Demand Rate
    int demand_;

    /// @brief Total Population of Delievery Site
    int population_;
};
#endif //CITIES_H
