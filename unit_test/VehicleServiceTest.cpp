//
// Created by Taoning Ge on 2022/6/9.
//

#include <iostream>
#include "VehicleServiceTest.h"
#include "../service/VehicleService.h"
#include "../model/Truck.h"
#include "../model/Car.h"
#include "../model/Bus.h"

auto vs = VehicleService::getInstance();

bool testAddTruck() {
    std::cout << "测试添加卡车" << std::endl;
    vs.clearVehicles();
    auto v = new Truck(1, "test", "test", 1, 1);
    vs.addVehicle(v);
    return Vehicle::getVehicleType(vs.queryVehicle(0)) == Truck::TYPE;
}

bool testAddCar() {
    std::cout << "测试添加小轿车" << std::endl;
    vs.clearVehicles();
    auto v = new Car(1, "test", "test", 1, 1);
    vs.addVehicle(v);
    return Vehicle::getVehicleType(vs.queryVehicle(0)) == Car::TYPE;
}

bool testAddBus() {
    std::cout << "测试添加大客车" << std::endl;
    vs.clearVehicles();
    auto v = new Bus(1, "test", "test", 1, 1);
    vs.addVehicle(v);
    return Vehicle::getVehicleType(vs.queryVehicle(0)) == Bus::TYPE;
}

bool testRemoveVehicle() {
    std::cout << "测试删除车辆" << std::endl;
    vs.clearVehicles();
    auto v = new Bus(1, "test", "test", 1, 1);
    vs.addVehicle(v);
    vs.removeVehicle(0);
    return vs.queryVehicle().empty();
}

bool testClearVehicles() {
    std::cout << "测试清空车辆" << std::endl;
    vs.clearVehicles();
    auto v = new Bus(1, "test", "test", 1, 1);
    auto v2 = new Bus(2, "test", "test", 1, 1);
    vs.addVehicle(v);
    vs.addVehicle(v2);
    vs.clearVehicles();
    return vs.queryVehicle().empty();
}

bool testUpdateVehicle() {
    std::cout << "测试更新车辆" << std::endl;
    vs.clearVehicles();
    auto v = new Bus(1, "test", "test", 1, 1);
    vs.addVehicle(v);
    auto v2 = new Car(2, "test", "test", 1, 1);
    vs.updateVehicle(0, v2);
    return Vehicle::getVehicleType(vs.queryVehicle(0)) == Car::TYPE;
}

bool testQueryVehicleInt() {
    std::cout << "测试获取车辆" << std::endl;
    vs.clearVehicles();
    auto v = new Bus(1, "test", "test", 1, 1);
    vs.addVehicle(v);
    return vs.queryVehicle(0)->getId() == 1 && vs.queryVehicle(0)->getLicenseNumber() == "test" &&
           vs.queryVehicle(0)->getManufacturer() == "test" && vs.queryVehicle(0)->getPurchaseYear() == 1;
}
