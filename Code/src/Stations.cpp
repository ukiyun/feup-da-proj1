#include "../include/Stations.h"

Station::Station(int station_id, string station_code) {
    station_id_ = station_id;
    station_code_ = station_code;
}

int Station::getStationId() const {
    return station_id_;
}

string Station::getStationCode() const {
    return station_code_;
}
