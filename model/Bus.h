//
// Created by Taoning Ge on 2022/6/7.
//

#ifndef CPP_BIG_HOMEWORK_BUS_H
#define CPP_BIG_HOMEWORK_BUS_H

#include <string>
#include "Vehicle.h"

/**
 * 大客车类
 */
class Bus : public Vehicle {
private:
    /**
     * 载客量
     */
    int load;

public:
    /**
     * 类型：大客车
     */
    const int TYPE = 3;

    Bus(int, int, std::string, int, int);

    int getLoad() const;

    std::string toString() const override;
};


#endif //CPP_BIG_HOMEWORK_BUS_H
