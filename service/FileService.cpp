//
// Created by Taoning Ge on 2022/6/8.
//

#include <fstream>
#include "FileService.h"
#include "../Utils.h"
#include "../model/Person.h"
#include "../model/Truck.h"
#include "../model/Car.h"
#include "../model/Bus.h"
#include "VehicleService.h"

extern Person person;

bool FileService::saveToFile() {
    std::string filePath = Utils::getFilePath();
    std::ofstream fout(filePath.c_str(), std::ios::binary);
    if (!fout) {
        return false;
    }

    // =============== write person =================
    size_t name_len = person.getName().length();
    fout.write((char *) &name_len, sizeof(size_t));
    fout.write(person.getName().c_str(), name_len);
    fout.write((char *) &person.getBirthday(), sizeof(Date));
    size_t id_len = person.getId().length();
    fout.write((char *) &id_len, sizeof(size_t));
    fout.write(person.getId().c_str(), id_len);

    // =============== write vehicle =================
    auto list = VehicleService::getInstance().queryVehicle();
    size_t size = list.size();
    fout.write((char *) &size, sizeof(size_t));
    for (auto &v: list) {
        auto vehicleType = Vehicle::getVehicleType(v);
        auto vehicleId = v->getId();
        auto vehicleLicenseNumber = v->getLicenseNumber();
        auto vehicleManufacturer = v->getManufacturer();
        auto vehiclePurchaseYear = v->getPurchaseYear();
        fout.write((char *) &vehicleType, sizeof(int));
        fout.write((char *) &vehicleId, sizeof(int));
        size_t licenseNumber_len = vehicleLicenseNumber.length();
        fout.write((char *) &licenseNumber_len, sizeof(size_t));
        fout.write(vehicleLicenseNumber.c_str(), licenseNumber_len);
        size_t manufacturer_len = vehicleManufacturer.length();
        fout.write((char *) &manufacturer_len, sizeof(size_t));
        fout.write(vehicleManufacturer.c_str(), manufacturer_len);
        fout.write((char *) &vehiclePurchaseYear, sizeof(int));
        switch (vehicleType) {
            case Truck::TYPE: {
                auto *t = dynamic_cast<Truck *>(v);
                auto truckWeight = t->getWeight();
                fout.write((char *) &truckWeight, sizeof(int));
                break;
            }
            case Car::TYPE: {
                auto *c = dynamic_cast<Car *>(v);
                auto carSeats = c->getSeats();
                fout.write((char *) &carSeats, sizeof(int));
                break;
            }
            case Bus::TYPE: {
                auto *b = dynamic_cast<Bus *>(v);
                auto busCapacity = b->getCapacity();
                fout.write((char *) &busCapacity, sizeof(int));
                break;
            }
            default:
                break;
        }
    }

    fout.flush();
    fout.close();
    return true;
}

bool FileService::loadFromFile() {
    VehicleService::getInstance().clearVehicles();

    std::string filePath = Utils::getFilePath();
    std::ifstream fin(filePath.c_str(), std::ios::binary);
    if (!fin) {
        return false;
    }

    // =============== read person =================
    size_t name_len;
    fin.read((char *) &name_len, sizeof(size_t));   // 获取姓名长度
    char *name = new char[name_len + 1];
    fin.read(name, name_len);   // 获取姓名
    name[name_len] = '\0';
    person.setName(name);

    Date birthday(0, 0, 0);
    fin.read((char *) &birthday, sizeof(Date)); // 获取生日
    person.setBirthday(birthday);

    size_t id_len;
    fin.read((char *) &id_len, sizeof(size_t)); // 获取身份证号长度
    char *id = new char[id_len + 1];
    fin.read(id, id_len);   // 获取身份证号
    id[id_len] = '\0';
    person.setId(id);

    delete[] name;
    delete[] id;

    // =============== read vehicle =================
    size_t size;    // 车的数量
    fin.read((char *) &size, sizeof(size_t));
    for (size_t i = 0; i < size; i++) {
        int vehicleType;
        fin.read((char *) &vehicleType, sizeof(int));   // 车的类型

        int vehicleId;
        fin.read((char *) &vehicleId, sizeof(int));     // 获取车辆编号

        size_t licenseNumber_len;
        fin.read((char *) &licenseNumber_len, sizeof(size_t));  // 获取车牌号长度
        char *licenseNumber = new char[licenseNumber_len + 1];
        fin.read(licenseNumber, licenseNumber_len);     // 获取车牌号
        licenseNumber[licenseNumber_len] = '\0';

        size_t manufacturer_len;
        fin.read((char *) &manufacturer_len, sizeof(size_t));   // 获取制造商长度
        char *manufacturer = new char[manufacturer_len + 1];
        fin.read(manufacturer, manufacturer_len);     // 获取制造商
        manufacturer[manufacturer_len] = '\0';

        int purchaseYear;
        fin.read((char *) &purchaseYear, sizeof(int));   // 获取购买年份

        switch (vehicleType) {
            case Truck::TYPE: {
                int weight;
                fin.read((char *) &weight, sizeof(int));   // 获取车辆重量
                auto *t = new Truck(vehicleId, licenseNumber, manufacturer, purchaseYear, weight);
                VehicleService::getInstance().addVehicle(t);

                break;
            }
            case Car::TYPE: {
                int seats;
                fin.read((char *) &seats, sizeof(int));   // 获取车辆座位数
                auto *c = new Car(vehicleId, licenseNumber, manufacturer, purchaseYear, seats);
                VehicleService::getInstance().addVehicle(c);

                break;
            }
            case Bus::TYPE: {
                int capacity;
                fin.read((char *) &capacity, sizeof(int));   // 获取车辆容量
                auto *b = new Bus(vehicleId, licenseNumber, manufacturer, purchaseYear, capacity);
                VehicleService::getInstance().addVehicle(b);

                break;
            }
            default:
                break;
        }
    }

    fin.close();
    return true;
}
