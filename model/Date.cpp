//
// Created by Taoning Ge on 2022/6/7.
//

#include <string>
#include "Date.h"

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

std::string Date::toString() const {
    return "Date(" + std::to_string(year) + ", " + std::to_string(month) + ", " + std::to_string(day) + ")";
}

