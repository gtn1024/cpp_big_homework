//
// Created by Taoning Ge on 2022/6/7.
//

#ifndef CPP_BIG_HOMEWORK_TRUCK_H
#define CPP_BIG_HOMEWORK_TRUCK_H


#include "Vehicle.h"

/**
 * 卡车类
 */
class Truck : public Vehicle {
private:
    /**
     * 车辆载重
     */
    int weight;

public:
    Truck(int, int, std::string, int, int);

    int getWeight() const;

    std::string toString() const override;
};


#endif //CPP_BIG_HOMEWORK_TRUCK_H
