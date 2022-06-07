//
// Created by Taoning Ge on 2022/6/7.
//

#ifndef CPP_BIG_HOMEWORK_PERSONSERVICE_H
#define CPP_BIG_HOMEWORK_PERSONSERVICE_H

#include "../model/Person.h"

class PersonService {
private:
    PersonService();

    Person *person;

public:
    static PersonService &getInstance();    // 单例模式

    void setPerson(Person &);

    Person *getPerson();
};


#endif //CPP_BIG_HOMEWORK_PERSONSERVICE_H
