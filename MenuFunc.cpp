//
// Created by Taoning Ge on 2022/6/7.
//

#include <iostream>
#include "MenuFunc.h"
#include "model/Date.h"
#include "model/Person.h"
#include "model/Vehicle.h"
#include "model/Car.h"
#include "model/Bus.h"
#include "model/Truck.h"
#include "service/VehicleService.h"

using namespace std;

extern Person person;

void MenuFunc::showMenu() {
    cout << endl;
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    cout << "||                       菜单                        " << endl;
    cout << "||" << endl;
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
    cout << endl;
    cout << "请输入操作序号：";
    int op;
    cin >> op;
    switch (op) {
        case 1:
            // 个人信息
            showPersonAndOperator();
            break;
        case 2:
            // 车辆列表
            showVehicleList();
            break;
        case 3:
            // 车辆入库
            addVehicle();
            break;
        case 4:
            // 车辆出库
            removeVehicle();
            break;
        case 5:
            // 车辆修改
            modifyVehicle();
            break;
        case 6:
            // 车辆查询
            queryVehicle();
            break;
        case 7:
            // 车辆清空
            clearVehicle();
            break;
        case 8:
            // 数据存储
            saveData();
            break;
        case 9:
            // 数据读取
            readData();
            break;
        default:
            // 退出系统
            exit(0);
    }
}

void MenuFunc::showPersonAndOperator() {
    while (true) {
        cout << endl;
        cout << "   ================================================ " << endl;
        cout << "||" << endl;
        cout << "||                     个人信息                      " << endl;
        cout << "||" << endl;
        cout << "   ================================================ " << endl;
        cout << "||" << endl;
        cout << "||  姓名：" << person.getName() << endl;
        cout << "||  出生日期：" << person.getBirthday().toString() << endl;
        cout << "||  身份证号：" << person.getId() << endl;
        cout << "||" << endl;
        cout << "   ================================================ " << endl;
        cout << "||" << endl;
        cout << "||      1. 修改信息         0. 退出菜单" << endl;
        cout << "||" << endl;
        cout << "   ================================================ " << endl;
        cout << endl;
        cout << "请输入操作序号：";
        int op;
        cin >> op;
        switch (op) {
            case 1:
                // 修改信息
                modifyPerson();
                break;
            case 0:
                // 退出菜单
                return;
        }
    }
}

void MenuFunc::modifyPerson() {
    string name, id;
    int y, m, d;
    cout << endl;
    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入出生日期（以空格分割）：";
    cin >> y >> m >> d;
    Date birthday(y, m, d);
    cout << "请输入身份证号：";
    cin >> id;
    person.setName(name);
    person.setBirthday(birthday);
    person.setId(id);
    cout << "修改成功！" << endl;
}

void MenuFunc::showVehicleList() {
    cout << endl;
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    cout << "||                     车辆列表                      " << endl;
    cout << "||" << endl;
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    showVehicleListTips();
    cout << "||" << endl;
    showOnlyExitMenuTips();
}

Vehicle *MenuFunc::newVehicleTips() {
    int type, id, purchaseYear;
    string licenseNumber, manufacturer;
    cout << "请选择车辆类型（1为卡车，2为小轿车，3为大客车）：";
    cin >> type;
    if (type < 1 || type > 3) {
        return nullptr;
    }
    cout << "请输入车辆编号：";
    cin >> id;
    cout << "请输入车牌号：";
    cin >> licenseNumber;
    cout << "请输入车辆制造商：";
    cin >> manufacturer;
    cout << "请输入购买年份：";
    cin >> purchaseYear;
    Vehicle *v;
    switch (type) {
        case 1:
            // 卡车
            int weight;
            cout << "请输入车辆载重：";
            cin >> weight;
            v = new Truck(id, licenseNumber, manufacturer, purchaseYear, weight);
            break;
        case 2:
            // 小轿车
            int seats;
            cout << "请输入车辆座位数：";
            cin >> seats;
            v = new Car(id, licenseNumber, manufacturer, purchaseYear, seats);
            break;
        case 3:
            // 大客车
            int capacity;
            cout << "请输入车辆载客量：";
            cin >> capacity;
            v = new Bus(id, licenseNumber, manufacturer, purchaseYear, capacity);
            break;
        default:
            return nullptr;
    }
    return v;
}

bool MenuFunc::showVehicleListTips() {
    auto ls = VehicleService::getInstance().queryVehicle();
    if (ls.empty()) {
        cout << "||                   暂无车辆信息                       " << endl;
        return false;
    } else {
        for (int i = 0; i < ls.size(); ++i) {
            cout << "||  " << std::to_string(i) << " " << ls[i]->toString() << endl;
        }
    }
    return true;
}

void MenuFunc::showOnlyExitMenuTips() {
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    cout << "||      任意数字退出" << endl;
    cout << "||" << endl;
    cout << "   ================================================ " << endl;
    int _;
    cin >> _;
}

void MenuFunc::addVehicle() {
    cout << endl;
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    cout << "||                     车辆入库                      " << endl;
    cout << "||" << endl;
    cout << "   ================================================ " << endl;
    cout << endl;
    Vehicle *v = newVehicleTips();
    if (v == nullptr) {
        cout << "输入错误！" << endl;
    } else {
        VehicleService::getInstance().addVehicle(v);
    }
    showOnlyExitMenuTips();
}

void MenuFunc::removeVehicle() {
    cout << endl;
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    cout << "||                     车辆出库                      " << endl;
    cout << "||" << endl;
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    if (showVehicleListTips()) {
        cout << "||" << endl;
        cout << "   ================================================ " << endl;
        cout << endl;
        cout << "请输入车辆序号：";
        int id;
        cin >> id;
        if (VehicleService::getInstance().removeVehicle(id)) {
            cout << "删除成功！" << endl;
        } else {
            cout << "删除失败！可能车辆序号不存在！" << endl;
        }
    }
    cout << "||" << endl;
    showOnlyExitMenuTips();
}

void MenuFunc::modifyVehicle() {
    cout << endl;
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    cout << "||                     车辆修改                      " << endl;
    cout << "||" << endl;
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    if (showVehicleListTips()) {
        cout << "||" << endl;
        cout << "   ================================================ " << endl;
        cout << endl;
        cout << "请输入车辆序号：";
        int id;
        cin >> id;
        Vehicle *v = newVehicleTips();
        if (v == nullptr) {
            cout << "输入错误！" << endl;
        } else {
            VehicleService::getInstance().updateVehicle(id, v);
        }
    }
}

void MenuFunc::queryVehicle() {
    cout << endl;
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    cout << "||                     车辆查询                      " << endl;
    cout << "||" << endl;
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    if (showVehicleListTips()) {
        cout << "||" << endl;
        cout << "   ================================================ " << endl;
        cout << endl;
        cout << "请输入车辆序号：";
        int id;
        cin >> id;
        auto v = VehicleService::getInstance().queryVehicle(id);
        if (v == nullptr) {
            cout << "查询失败！可能车辆序号不存在！" << endl;
        } else {
            cout << "查询成功！" << endl;
            auto type = Vehicle::getVehicleType(v);
            cout << "车辆类型：" << Vehicle::getVehicleTypeName(v) << endl;
            cout << "车辆编号：" << v->getId() << endl;
            cout << "车牌号：" << v->getLicenseNumber() << endl;
            cout << "制造商名称：" << v->getManufacturer() << endl;
            cout << "车辆购买年份：" << v->getPurchaseYear() << endl;
            switch (type) {
                case Truck::TYPE: {
                    // https://blog.csdn.net/sinat_18897273/article/details/52402391
                    auto *t = dynamic_cast<Truck *>(v);
                    cout << "车辆载重：" << t->getWeight() << endl;
                    break;
                }
                case Car::TYPE: {
                    auto *c = dynamic_cast<Car *>(v);
                    cout << "座位数：" << c->getSeats() << endl;
                    break;
                }
                case Bus::TYPE: {
                    auto *b = dynamic_cast<Bus *>(v);
                    cout << "载客量：" << b->getCapacity() << endl;
                    break;
                }
                default:
                    break;
            }
        }
    }
    showOnlyExitMenuTips();
}

void MenuFunc::clearVehicle() {
    cout << endl;
    cout << "   ================================================ " << endl;
    cout << "||" << endl;
    cout << "||                  确认清空车辆吗？                      " << endl;
    cout << "||" << endl;
    cout << "||       1. 确认                     2. 取消 " << endl;
    cout << "||" << endl;
    cout << "   ================================================ " << endl;
    cout << endl;
    cout << "请输入操作序号：";
    int op;
    cin >> op;
    switch (op) {
        case 1:
            // 确认清空
            VehicleService::getInstance().clearVehicles();
            cout << "清空成功！" << endl;
            break;
        case 2:
            // 取消清空
            cout << "取消清空！" << endl;
            break;
        default:
            cout << "输入错误！" << endl;
            break;
    }
}

void MenuFunc::saveData() {
    // TODO: implement
}

void MenuFunc::readData() {
    // TODO: implement
}
