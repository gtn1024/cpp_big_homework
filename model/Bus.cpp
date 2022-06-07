//
// Created by Taoning Ge on 2022/6/7.
//

#include "Bus.h"

Bus::Bus(int id, int licenseNumber, std::string manufacturer, int purchaseYear, int load) :
        Vehicle(id, licenseNumber, manufacturer, purchaseYear), load(load) {}

int Bus::getLoad() const {
    return load;
}

std::string Bus::toString() const {
    return "Bus(" + std::to_string(id) + ", " + std::to_string(licenseNumber) + ", " + manufacturer +
           ", " + std::to_string(purchaseYear) + ", " + std::to_string(load) + ")";
}

