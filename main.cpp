#include <iostream>
#include "Utils.h"
#include "model/Truck.h"
#include "model/Car.h"
#include "model/Bus.h"
#include "model/Person.h"

using namespace std;

void test();

void showMenu();

int main() {
//    test();
    while (true) {
        showMenu();
    }
    return 0;
}

void showMenu() {
    cout << "   ================================================ " << endl;
    cout << "||                       菜单                        " << endl;
    cout << "   ================================================ " << endl;
    cout << "||  1. 个人信息" << endl;
    cout << "||  2. 车辆列表" << endl;
    cout << "||  3. 车辆入库" << endl;
    cout << "||  4. 车辆出库" << endl;
    cout << "||  5. 车辆修改" << endl;
    cout << "||  6. 车辆查询" << endl;
    cout << "||  7. 车辆清空" << endl;
    cout << "||  8. 数据存储" << endl;
    cout << "||  9. 数据读取" << endl;
    cout << "||  0. 退出系统" << endl;
    cout << "   ================================================ " << endl;
    cout << "请输入操作序号：";
    int op;
    cin >> op;
    switch (op) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 0:
            exit(0);
            break;
    }
}

void test() {
    cout << "---------------- 工具类测试 ----------------" << endl;
    cout << Utils::getSystem() << endl;
    cout << Utils::getUserHome() << endl;

    cout << "---------------- 卡车类测试 ----------------" << endl;
    Truck truck(1, 2, "getn的厂", 1990, 100);
    cout << truck.toString() << endl;
    cout << truck.getId() << ", "
         << truck.getLicenseNumber() << ", "
         << truck.getManufacturer() << ", "
         << truck.getPurchaseYear() << ", "
         << truck.getWeight() << endl;

    cout << "---------------- 小轿车类测试 ----------------" << endl;
    Car car(1, 2, "getaoning.com", 2002, Car::LARGE);
    cout << car.toString() << endl;
    cout << car.getId() << ", "
         << car.getLicenseNumber() << ", "
         << car.getManufacturer() << ", "
         << car.getPurchaseYear() << ", "
         << car.getSeats() << endl;

    cout << "---------------- 大客车类测试 ----------------" << endl;
    Bus bus(1, 2, "gtn1024", 2022, 30);
    cout << bus.toString() << endl;
    cout << bus.getId() << ", "
         << bus.getLicenseNumber() << ", "
         << bus.getManufacturer() << ", "
         << bus.getPurchaseYear() << ", "
         << bus.getLoad() << endl;

    cout << "---------------- 人类测试 ----------------" << endl;
    Date d(2004, 6, 16);
    Person person("getn", d, "322882200406168822"); // 永远 18 岁
    cout << person.toString() << endl;
    cout << person.getName() << ", "
         << person.getBirthday().toString() << ", "
         << person.getId() << endl;
}
