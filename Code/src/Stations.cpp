#include "../include/Stations.h"

Stations::Stations(int station_id, string station_code) {
    station_id_ = station_id;
    station_code_ = station_code;
}

int Stations::getStationId() const {
    return station_id_;
}

string Stations::getStationCode() const {
    return station_code_;
}
