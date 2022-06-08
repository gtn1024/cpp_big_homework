#include <iostream>
#include "MenuFunc.h"
#include "Utils.h"
#include "model/Truck.h"
#include "model/Car.h"
#include "model/Bus.h"
#include "model/Person.h"

using namespace std;

Date d(2022, 6, 16);
Person person("default", d, "123456789");

void test();

int main() {
//    test();
    while (true) {
        MenuFunc::showMenu();
    }
    return 0;
}


void test() {
    cout << "---------------- 工具类测试 ----------------" << endl;
    cout << Utils::getSystem() << endl;
    cout << Utils::getUserHome() << endl;
    cout << Utils::getFilePath() << endl;

    cout << "---------------- 卡车类测试 ----------------" << endl;
    Truck truck(1, "123", "getn的厂", 1990, 100);
    cout << truck.toString() << endl;
    cout << truck.getId() << ", "
         << truck.getLicenseNumber() << ", "
         << truck.getManufacturer() << ", "
         << truck.getPurchaseYear() << ", "
         << truck.getWeight() << endl;

    cout << "---------------- 小轿车类测试 ----------------" << endl;
    Car car(1, "234", "getaoning.com", 2002, Car::LARGE);
    cout << car.toString() << endl;
    cout << car.getId() << ", "
         << car.getLicenseNumber() << ", "
         << car.getManufacturer() << ", "
         << car.getPurchaseYear() << ", "
         << car.getSeats() << endl;

    cout << "---------------- 大客车类测试 ----------------" << endl;
    Bus bus(1, "345", "gtn1024", 2022, 30);
    cout << bus.toString() << endl;
    cout << bus.getId() << ", "
         << bus.getLicenseNumber() << ", "
         << bus.getManufacturer() << ", "
         << bus.getPurchaseYear() << ", "
         << bus.getCapacity() << endl;

    cout << "---------------- 人类测试 ----------------" << endl;
    Date d(2004, 6, 16);
    Person person("getn", d, "322882200406168822"); // 永远 18 岁
    cout << person.toString() << endl;
    cout << person.getName() << ", "
         << person.getBirthday().toString() << ", "
         << person.getId() << endl;

    cout << "---------------- 人类修改 ----------------" << endl;
    person.setName("gtn1024");
    Date d2(2000, 6, 16);
    person.setBirthday(d2);
    person.setId("123456789987654321");
    cout << person.toString() << endl;

}
