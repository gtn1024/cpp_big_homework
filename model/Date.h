//
// Created by Taoning Ge on 2022/6/7.
//

#ifndef CPP_BIG_HOMEWORK_DATE_H
#define CPP_BIG_HOMEWORK_DATE_H


class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int, int, int);

    int getYear() const;

    int getMonth() const;

    int getDay() const;

    std::string toString() const;
};


#endif //CPP_BIG_HOMEWORK_DATE_H
