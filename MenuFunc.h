//
// Created by Taoning Ge on 2022/6/7.
//

#ifndef CPP_BIG_HOMEWORK_MENUFUNC_H
#define CPP_BIG_HOMEWORK_MENUFUNC_H


class MenuFunc {
public:
    /**
     * 显示总列表
     */
    static void showMenu();

    /**
     * 个人信息
     */
    static void showPersonAndOperator();

    /**
     * 车辆列表
     */
    static void showVehicleList();

    /**
     * 车辆入库
     */
    static void addVehicle();

    /**
     * 车辆出库
     */
    static void removeVehicle();

    /**
     * 车辆修改
     */
    static void modifyVehicle();

    /**
     * 车辆查询
     */
    static void queryVehicle();

    /**
     * 车辆清空
     */
    static void clearVehicle();

    /**
     * 数据存储
     */
    static void saveData();

    /**
     * 数据读取
     */
    static void readData();
};


#endif //CPP_BIG_HOMEWORK_MENUFUNC_H
