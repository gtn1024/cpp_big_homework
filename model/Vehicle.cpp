//
// Created by Taoning Ge on 2022/6/7.
//

#include "Vehicle.h"

Vehicle::Vehicle(int id, std::string licenseNumber, std::string manufacturer, int purchaseYear) :
        id(id), licenseNumber(licenseNumber), manufacturer(manufacturer), purchaseYear(purchaseYear) {}

int Vehicle::getId() const {
    return id;
}

std::string Vehicle::getLicenseNumber() const {
    return licenseNumber;
}

std::string Vehicle::getManufacturer() const {
    return manufacturer;
}

int Vehicle::getPurchaseYear() const {
    return purchaseYear;
}

