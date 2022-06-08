//
// Created by Taoning Ge on 2022/6/7.
//

#include "VehicleService.h"

VehicleService::VehicleService() = default;

VehicleService &VehicleService::getInstance() {
    static VehicleService instance;
    return instance;
}

void VehicleService::addVehicle(Vehicle *vehicle) {
    list.push_back(vehicle);
}

bool VehicleService::removeVehicle(int id) {
    if (id < 0 || id >= list.size()) {
        return false;
    }
    Vehicle::deleteObject(list[id]);
    list.erase(list.begin() + id);
    return true;
}

void VehicleService::clearVehicles() {
    for (auto &v: list) {
        Vehicle::deleteObject(v);
    }
    list.clear();
}

bool VehicleService::updateVehicle(int id, Vehicle *vehicle) {
    if (id < 0 || id >= list.size()) {
        return false;
    }
    Vehicle::deleteObject(list[id]);
    list[id] = vehicle;
    return true;
}

std::vector<Vehicle *> &VehicleService::queryVehicle() {
    return list;
}

Vehicle *VehicleService::queryVehicle(int id) {
    if (id < 0 || id >= list.size()) {
        return nullptr;
    }
    return list[id];
}
