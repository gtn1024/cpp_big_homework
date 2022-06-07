//
// Created by Taoning Ge on 2022/6/7.
//

#include "Truck.h"

Truck::Truck(int id, int licenseNumber, std::string manufacturer, int purchaseYear, int weight) :
        Vehicle(id, licenseNumber, manufacturer, purchaseYear), weight(weight) {}

int Truck::getWeight() const {
    return weight;
}

std::string Truck::toString() const {
    return "Truck(" + std::to_string(id) + ", " + std::to_string(licenseNumber) + ", " + manufacturer +
           ", " + std::to_string(purchaseYear) + ", " + std::to_string(weight) + ")";
}

