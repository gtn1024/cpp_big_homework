#include <iostream>
#include "MenuFunc.h"
#include "Utils.h"
#include "model/Person.h"
#include "unit_test/VehicleServiceTest.h"
#include "service/FileService.h"

using namespace std;

Date d(2022, 6, 16);
Person person("default", d, "123456789");

void runUnitTest();

int main() {
//    runUnitTest();

    if (!FileService::loadFromFile()) {
        cout << "当前未设置车主信息！" << endl;
        MenuFunc::modifyPerson();
        cout << "设置成功！" << endl;
    }

    while (true) {
        MenuFunc::showMenu();
    }
    return 0;
}

void runUnitTest() {
    cout << "---------------- 工具类测试 ----------------" << endl;
    cout << Utils::getSystem() << endl;
    cout << Utils::getUserHome() << endl;
    cout << Utils::getFilePath() << endl;

    if (testAddTruck() && testAddCar() && testAddBus() && testRemoveVehicle() && testClearVehicles() &&
        testUpdateVehicle() && testQueryVehicleInt()) {
        cout << "---------------- 单元测试通过 ----------------" << endl;
    } else {
        cout << "---------------- 单元测试失败 ----------------" << endl;
    }
}
