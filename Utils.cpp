//
// Created by Taoning Ge on 2022/6/7.
//

#include "Utils.h"
#include <string>
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
    std::string res;
    if (getSystem()) {
        res = std::getenv("HOME");
    } else {
        res = std::getenv("USERPROFILE");
    }
    return res;
}

std::string Utils::getFilePath() {
    return getUserHome() + (getSystem() ? '/' : '\\') + "gtn1024_vehicle_manager.dat";
}

void Utils::exitProg() {
    FileService::saveToFile();
    exit(0);
}


