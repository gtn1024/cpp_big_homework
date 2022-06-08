//
// Created by Taoning Ge on 2022/6/7.
//

#include "VehicleService.h"

VehicleService::VehicleService() {

}

VehicleService &VehicleService::getInstance() {
    static VehicleService instance;
    return instance;
}

void VehicleService::addVehicle(Vehicle *vehicle) {
    list.push_back(vehicle);
}

bool VehicleService::removeVehicle(int id) {
    for (auto it = list.begin(); it != list.end(); it++) {
        if ((*it)->getId() == id) {
            list.erase(it);
            return true;
        }
    }
    return false;
}

bool VehicleService::updateVehicle(int id, Vehicle *vehicle) {
    for (auto &it: list) {
        if (it->getId() == id) {
            it = vehicle;
            return true;
        }
    }
    return false;
}

std::vector<Vehicle *> &VehicleService::queryVehicle() {
    return list;
}

Vehicle *VehicleService::queryVehicle(int id) {
    for (auto &it: list) {
        if (it->getId() == id) {
            return it;
        }
    }
    return nullptr;
}
