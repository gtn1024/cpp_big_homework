//
// Created by Taoning Ge on 2022/6/7.
//

#include "Utils.h"
#include <string>
#include <iostream>
#include "service/FileService.h"

int Utils::getSystem() {
    int res = 0;
#ifdef _WIN32
    res = 0;
#elif __linux__
    res = 1;
#elif __APPLE__
    res = 2;
#endif
    return res;
}

std::string Utils::getUserHome() {
    std::string res = std::getenv(getSystem() ? "HOME" : "USERPROFILE");
    return res;
}

std::string Utils::getFilePath() {
    return getUserHome() + (getSystem() ? '/' : '\\') + "gtn1024_vehicle_manager.dat";
}

void Utils::exitProgram() {
    if (FileService::saveToFile()) {
        std::cout << "保存成功！" << std::endl;
        std::cout << "文件名：" << getFilePath() << std::endl;
    } else {
        std::cout << "保存失败！" << std::endl;
    }
    std::cout << "正在退出……" << std::endl;
    exit(0);
}


