//
// Created by Taoning Ge on 2022/6/7.
//

#include "Vehicle.h"
#include "Truck.h"
#include "Car.h"
#include "Bus.h"

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

int Vehicle::getVehicleType(Vehicle *vehicle) {
    if (typeid(*vehicle) == typeid(Truck)) {
        return Truck::TYPE;
    } else if (typeid(*vehicle) == typeid(Car)) {
        return Car::TYPE;
    } else if (typeid(*vehicle) == typeid(Bus)) {
        return Bus::TYPE;
    } else {
        return 0;
    }
}

std::string Vehicle::getVehicleTypeName(Vehicle *v) {
    std::string typeName;
    switch (getVehicleType(v)) {
        case Truck::TYPE:
            typeName = "卡车";
            break;
        case Car::TYPE:
            typeName = "小轿车";
            break;
        case Bus::TYPE:
            typeName = "大客车";
            break;
        default:
            break;
    }
    return typeName;
}



