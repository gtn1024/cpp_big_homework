//
// Created by Taoning Ge on 2022/6/7.
//

#ifndef CPP_BIG_HOMEWORK_PERSON_H
#define CPP_BIG_HOMEWORK_PERSON_H

#include <string>
#include "Date.h"

class Person {
private:
    /**
     * 姓名
     */
    std::string name;

    /**
     * 出生日期
     */
    Date birthday;

    /**
     * 身份证号
     */
    std::string id;

public:
    Person(std::string, Date &, std::string);

    void setName(std::string);

    std::string getName() const;

    void setBirthday(Date &);

    Date &getBirthday();

    void setId(std::string);

    std::string getId() const;

    std::string toString() const;
};


#endif //CPP_BIG_HOMEWORK_PERSON_H
