#include "../include/Cities.h"

Cities::Cities(string city, int city_id, string city_code, int demand, int population) {
    city_ = city;
    city_id_ = city_id;
    city_code_ = city_code;
    demand_ = demand;
    population_ = population;
}

string Cities::getCity() const {
    return city_;
}

int Cities::getCityId() const {
    return city_id_;
}

string Cities::getCityCode() const {
    return city_code_;
}

int Cities::getDemand() const {
    return demand_;
}

int Cities::getPopulation() const {
    return population_;
}




