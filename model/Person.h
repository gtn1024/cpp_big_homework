//
// Created by Taoning Ge on 2022/6/7.
//

#ifndef CPP_BIG_HOMEWORK_PERSON_H
#define CPP_BIG_HOMEWORK_PERSON_H

#include <string>
#include "Date.h"

class Person {
private:
    std::string name;
    Date birthday;
    std::string id;

public:
    Person(std::string, Date &, std::string);

    std::string getName() const;

    Date &getBirthday();

    std::string getId() const;

    std::string toString() const;
};


#endif //CPP_BIG_HOMEWORK_PERSON_H
