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
    VehicleService();

    std::vector<Vehicle *> list;

public:
    static VehicleService &getInstance();
};


#endif //CPP_BIG_HOMEWORK_VEHICLESERVICE_H
