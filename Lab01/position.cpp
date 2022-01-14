#include "position.h"

Position::Position(int latitude, int longitude) {
    this->latitude = latitude;
    this->longitude = longitude;
}

Position Position::Sum(Position a, Position b) {
    int newLatitude = a.latitude + b.latitude;
    int newLongitude = a.longitude + b.longitude;
    if(newLatitude > 90 || newLatitude < -90){
        newLatitude = 180 - abs(newLatitude);
    }
    if(newLongitude < -180){
        newLongitude = 360 + newLongitude;
    }
    else if(newLongitude > 180){
        newLongitude = newLongitude - 360;
    }
    return Position(newLatitude, newLongitude);
}

Position Position::Diff(Position a, Position b) {
    int newLatitude = a.latitude - b.latitude;
    int newLongitude = a.longitude - b.longitude;
    if(newLatitude > 90 || newLatitude < -90){
        newLatitude = 180 - abs(newLatitude);
    }
    if(newLongitude < -180){
        newLongitude = 360 + newLongitude;
    }
    else if(newLongitude > 180){
        newLongitude = newLongitude - 360;
    }
    return Position(newLatitude, newLongitude);
}

Position Position::Mult(Position a, Position b) {
    int newLatitude = a.latitude * b.latitude;
    int newLongitude = a.longitude * b.longitude;
    if (newLatitude > 90){
        newLatitude %= 90;
    }
    else if (newLatitude < -90) {
        newLatitude *= -1;
        newLatitude %= 90;
        newLatitude *= -1;
    }
    if (newLongitude > 180) {
        newLongitude %= 180;
    }
    else if (newLongitude < -180) {
        newLongitude *= -1;
        newLongitude %= 180;
        newLongitude *= -1;
    }
    return Position(newLatitude, newLongitude);
}

Position Position::Substr(Position a, Position b) {
    int newLatitude = a.latitude / b.latitude;
    int newLongitude = a.longitude / b.longitude;
    return Position(newLatitude, newLongitude);
}

bool operator ==(Position a, Position b) {
    return a.latitude == b.latitude && a.longitude == b.longitude;
}

void Position::Compare(Position a, Position b) {
    if (a == b){
        std::cout << "Positions are equal\n";
    }
    else {
        if (a.latitude == b.latitude) {
            std::cout << "Positions have the same latitude and ";
        }
        else if(a.latitude > b.latitude) {
            std::cout << "First position is northern than second and ";
        }
        else {
            std::cout << "Second position is northern than first and ";
        }
        if (a.longitude == b.longitude) {
            std::cout << "positions have the same longitude\n";
        }
        else if(a.longitude > b.longitude) {
            std::cout << "first position is eastern than second\n";
        }
        else {
            std::cout << "second position is eastern than first\n";
        }
    }
}

void Position::print() {
    std::cout << "latitude, longitude: (" << latitude << "," << longitude << ")\n";
}
