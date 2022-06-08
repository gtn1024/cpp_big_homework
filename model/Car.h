//
// Created by Taoning Ge on 2022/6/7.
//

#ifndef CPP_BIG_HOMEWORK_CAR_H
#define CPP_BIG_HOMEWORK_CAR_H

#include <string>
#include "Vehicle.h"

/**
 * 小轿车类
 */
class Car : public Vehicle {
private:
    /**
     * 座位数
     */
    int seats;

public:
    /**
     * 类型：小轿车
     */
    static const int TYPE = 2;

    const static int SMALL = 2;
    const static int MEDIUM = 5;
    const static int LARGE = 7;

    Car(int, std::string, std::string, int, int);

    int getSeats() const;

    std::string toString() const override;
};


#endif //CPP_BIG_HOMEWORK_CAR_H
