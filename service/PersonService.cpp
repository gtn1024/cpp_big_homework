//
// Created by Taoning Ge on 2022/6/7.
//

#include "PersonService.h"

PersonService::PersonService() {

}

PersonService &PersonService::getInstance() {
    static PersonService instance;
    return instance;
}

void PersonService::setPerson(Person &p) {
    person = &p;
}

Person *PersonService::getPerson() {
    return person;
}


