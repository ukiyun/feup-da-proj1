#include "../include/Cities.h"

City::City(string city, int city_id, string city_code, int demand, int population) {
    city_ = city;
    city_id_ = city_id;
    city_code_ = city_code;
    demand_ = demand;
    population_ = population;
}

string City::getCity() const {
    return city_;
}

int City::getCityId() const {
    return city_id_;
}

string City::getCityCode() const {
    return city_code_;
}

int City::getDemand() const {
    return demand_;
}

int City::getPopulation() const {
    return population_;
}




