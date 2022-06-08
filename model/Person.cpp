//
// Created by Taoning Ge on 2022/6/7.
//

#include "Person.h"

Person::Person(std::string name, Date &birthday, std::string id) : name(name), birthday(birthday), id(id) {}

void Person::setName(std::string name) {
    this->name = name;
}

std::string Person::getName() const {
    return name;
}

void Person::setBirthday(Date &date) {
    this->birthday = date;
}

Date &Person::getBirthday() {
    return birthday;
}

void Person::setId(std::string id) {
    this->id = id;
}

std::string Person::getId() const {
    return id;
}

std::string Person::toString() const {
    return "Person(" +
           name + ", " +
           birthday.toString() + ", " +
           id +
           ")";
}
