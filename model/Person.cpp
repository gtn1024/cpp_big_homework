//
// Created by Taoning Ge on 2022/6/7.
//

#include "Person.h"

Person::Person(std::string name, Date &birthday, std::string id) : name(name), birthday(birthday), id(id) {}

std::string Person::getName() const {
    return name;
}

Date &Person::getBirthday() {
    return birthday;
}

std::string Person::getId() const {
    return id;
}

std::string Person::toString() const {
    return "Person(" + name + ", " + birthday.toString() + ", " + id + ")";
}
