//
// Created by Taoning Ge on 2022/6/7.
//

#ifndef CPP_BIG_HOMEWORK_VEHICLESERVICE_H
#define CPP_BIG_HOMEWORK_VEHICLESERVICE_H

#include <vector>
#include <list>
#include "../model/Vehicle.h"


class VehicleService {
private:
    std::vector<Vehicle *> list;

    VehicleService();

public:
    static VehicleService &getInstance();

    void addVehicle(Vehicle *);

    bool removeVehicle(int);

    void clearVehicles();

    bool updateVehicle(int, Vehicle *);

    std::vector<Vehicle *> &queryVehicle();

    Vehicle *queryVehicle(int);
};


#endif //CPP_BIG_HOMEWORK_VEHICLESERVICE_H
