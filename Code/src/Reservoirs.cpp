#include "../include/Reservoirs.h"

Reservoir::Reservoir(string reservoir_name, string municipality, int reservoir_id, string reservoir_code, int max_delivery) {
    reservoir_name_ = reservoir_name;
    municipality_ = municipality;
    reservoir_id_ = reservoir_id;
    reservoir_code_ = reservoir_code;
    max_delivery_ = max_delivery;
}

string Reservoir::getReservoirName() const {
    return reservoir_name_;
}

string Reservoir::getMunicipality() const {
    return municipality_;
}

int Reservoir::getReservoirId() const {
    return reservoir_id_;
}

string Reservoir::getReservoirCode() const {
    return reservoir_code_;
}

int Reservoir::getMaxDelivery() const {
    return max_delivery_;
}


