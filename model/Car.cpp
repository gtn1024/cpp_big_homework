//
// Created by Taoning Ge on 2022/6/7.
//

#include "Car.h"

Car::Car(int id, std::string licenseNumber, std::string manufacturer, int purchaseYear, int seats) :
        Vehicle(id, licenseNumber, manufacturer, purchaseYear), seats(seats) {}

int Car::getSeats() const {
    return seats;
}

std::string Car::toString() const {
    return "Car(" +
           std::to_string(TYPE) + ", " +
           std::to_string(id) + ", " +
           licenseNumber + ", " +
           manufacturer + ", " +
           std::to_string(purchaseYear) + ", " +
           std::to_string(seats) +
           ")";
}

