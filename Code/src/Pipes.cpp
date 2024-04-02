#include "../include/Pipes.h"

#include <inttypes.h>

Pipe::Pipe(string service_point_a, string service_point_b, int capacity, bool direction) {
    service_point_a_ = service_point_a;
    service_point_b_ = service_point_b;
    capacity_ = capacity;
    direction_ = directio;
}

string Pipe::getPointA() const {
    return service_point_a_;
}

string Pipe::getPointB() const {
    return service_point_b_;
}

int Pipe::getCapacity() const{
    return capacity_;
}

bool Pipe::getDirection() const{
    return direction_;
}


