//
// Created by Taoning Ge on 2022/6/7.
//

#include "Bus.h"

Bus::Bus(int id, std::string licenseNumber, std::string manufacturer, int purchaseYear, int capacity) :
        Vehicle(id, licenseNumber, manufacturer, purchaseYear), capacity(capacity) {}

int Bus::getCapacity() const {
    return capacity;
}

std::string Bus::toString() const {
    return "Bus(" +
           std::to_string(TYPE) + ", " +
           std::to_string(id) + ", " +
           licenseNumber + ", " +
           manufacturer + ", " +
           std::to_string(purchaseYear) + ", " +
           std::to_string(capacity) +
           ")";
}

