#ifndef RESERVOIRS_H
#define RESERVOIRS_H

#include <string>
using namespace std;

/// @class Reservoir
/// @brief Stores the Information Regarding Water Reservoirs
class Reservoir {
public:
    /// @brief A Constructor for the Reservoir
    /// @param reservoir_name String with the Name of the Water Reservoir
    /// @param municipality String with the Name of the Municipality where the Water Reservoir is located
    /// @param reservoir_id Integer with the Unique Identifier of the Water Reservoir
    /// @param reservoir_code String with the Code of the Water Reservoir
    /// @param max_delivery Integer with the Maximum Delivery of the Water Reservoir in m^3/sec
    Reservoir(string reservoir_name, string municipality, int reservoir_id, string reservoir_code, int max_delivery); // Constructor

    /// @brief A Default Empty Constructor for the Water Reservoir
    Reservoir() = default; // Default Constructor

    /// @brief A Function used to get the Name of a Water Reservoir
    /// @return Returns the Name of a Water Reservoir
    string getReservoirName() const;    // Return the name of the reservoir

    /// @brief A Function used to get the Municipality of a Water Reservoir
    /// @return Returns the Municipality of a Water Reservoir
    string getMunicipality() const;     // Return the name of the municipality

    /// @brief A Function used to get the ID of a Water Reservoir
    /// @return Returns the ID of a Water Reservoir
    int getReservoirId() const;         // Return the reservoir id

    /// @brief A Function used to get the City of a Delivery Site
    /// @return Returns the City of a Delivery Site
    string getReservoirCode() const;    // Return the reservoir code

    /// @brief A Function used to get the City of a Delivery Site
    /// @return Returns the City of a Delivery Site
    int getMaxDelivery() const;         // Return the max delivery
private:
    /// @brief Water Reservoir Name
    string reservoir_name_;

    /// @brief Municipality where Water Reservoir is located
    string municipality_;

    /// @brief Id of Water Reservoir
    int reservoir_id_;

    /// @brief Code of Water Reservoir
    string reservoir_code_;

    /// @brief Maximum Delivery of Water Reservoir in m^3/sec
    int max_delivery_;
};
#endif //RESERVOIRS_H
