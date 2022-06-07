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
