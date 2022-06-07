//
// Created by Taoning Ge on 2022/6/7.
//

#ifndef CPP_BIG_HOMEWORK_VEHICLE_H
#define CPP_BIG_HOMEWORK_VEHICLE_H

#include <string>

/**
 * 车辆类
 */
class Vehicle {
protected:
    /**
     * 车辆编号
     */
    int id;

    /**
     * 车牌号
     */
    int licenseNumber;

    /**
     * 制造商名称
     */
    std::string manufacturer;

    /**
     * 车辆购买年份
     */
    int purchaseYear;

public:
    Vehicle(int, int, std::string, int);

    int getId() const;

    int getLicenseNumber() const;

    std::string getManufacturer() const;

    int getPurchaseYear() const;

    virtual std::string toString() const = 0;
};

#endif //CPP_BIG_HOMEWORK_VEHICLE_H
