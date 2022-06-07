//
// Created by Taoning Ge on 2022/6/7.
//

#include <iostream>
#include "MenuFunc.h"

using namespace std;

void MenuFunc::showMenu() {
    cout << endl;
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
        case 0:
            // 退出系统
            exit(0);
    }
}

void MenuFunc::showPersonAndOperator() {
    cout << endl;
    cout << "   ================================================ " << endl;
    cout << "||                     个人信息                      " << endl;
    cout << "   ================================================ " << endl;
    cout << "||  1. 显示个人信息" << endl;
    cout << "||  2. 修改个人信息" << endl;

}

void MenuFunc::showVehicleList() {
    // TODO: implement
}

void MenuFunc::addVehicle() {
    // TODO: implement
}

void MenuFunc::removeVehicle() {
    // TODO: implement
}

void MenuFunc::modifyVehicle() {
    // TODO: implement
}

void MenuFunc::queryVehicle() {
    // TODO: implement
}

void MenuFunc::clearVehicle() {
    // TODO: implement
}

void MenuFunc::saveData() {
    // TODO: implement
}

void MenuFunc::readData() {
    // TODO: implement
}
