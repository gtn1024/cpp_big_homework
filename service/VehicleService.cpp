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
    if (id < 0 || id >= list.size()) {
        return false;
    }
    auto it = list.begin() + id;
    // TODO: 根据对象类型销毁资源
    // delete *it;
    list.erase(it);
    return true;
}

void VehicleService::clearVehicles() {
    // TODO: 销毁资源
//    for (auto &v: list) {
//        delete v;
//    }
    list.clear();
}

bool VehicleService::updateVehicle(int id, Vehicle *vehicle) {
    if (id < 0 || id >= list.size()) {
        return false;
    }
    auto it = list.begin() + id;
    auto before = *it;
    // TODO: 根据对象类型销毁资源
    // delete before;
    *it = vehicle;
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
