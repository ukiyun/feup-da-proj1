#ifndef PIPES_H
#define PIPES_H

#include <string>

using namespace std;

/// @class Pipe
/// @brief Stores the Information Regarding the Pipelines
class Pipe {
public:
    ///@brief A Constructor for the Pumping Station
    ///@param service_point_a String with the Source Service (Reservoir, Station, Cities)
    ///@param service_point_b String with the Target Service (Reservoir, Station, Cities)
    ///@param capacity Integer with the Maximum Capacity of the Pipeline
    ///@param direction Boolean indicating if connection is uni or bi directional (0 = bi, 1 = uni)
    Pipe(string service_point_a, string service_point_b, int capacity, bool direction);

    ///@brief A Default Empty Constructor for the Pipeline
    Pipe() = default;

    ///@brief A Function used to get the name of the Source Service
    ///@return Returns the String of the Source Service
    string getPointA() const;

    ///@brief A Function used to get the name of the Target Service
    ///@return Returns the String of the Target Service
    string getPointB() const;

    ///@brief A Function used to get the Maximum Capacity of the Pipe
    ///@return Returns the Integer of the Maximum Capacity
    int getCapacity() const;

    ///@brief A Function used to get the name of the direction of the Pipe
    ///@return Returns a Boolean with the values 0 or 1, 1 being unidirectional and 0 being bidirectional
    bool getDirection() const;
private:
    ///@brief Source Service that can be Reservoir, Station or Delivery Site (Cities)
    string service_point_a_;

    ///@brief Target Service that can be Reservoir, Station or Delivery Site (Cities)
    string service_point_b_;

    ///@brief Maximum Capacity of the Pipe
    int capacity_;

    ///@brief Boolean indicating whether the connection between source and target is undirected, 1 = unidirectional, 0 = biderectional
    bool direction_;
};

#endif //PIPES_H
