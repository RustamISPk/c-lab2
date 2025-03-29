#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "AbstractOne.h"


using namespace std;

struct Costyl {
    int a;
    int b;
    size_t result;
};

class Person : AbstractOne{
public:
    Person(string name, string surname, string patronymic, string birthdate) {
        this->name = name;
        this->surname = surname;
        this->patronymic = patronymic;
        this->birthdate = birthdate;
    };

    Person(string name, string surname, string birthdate) {
        this->name = name;
        this->surname = surname;
        // this->patronymic = patronymic;
        this->birthdate = birthdate;
    };

    vector<string> getPersonData() override {
        this->personData.push_back(this->name);
        this->personData.push_back(this->surname);
        this->personData.push_back(this->patronymic);
        this->personData.push_back(this->birthdate);
        return this->personData;
    };

    template<typename T>
    Costyl lengthName(T a) {
        if constexpr (is_same_v<T, char>) {
            cout << "Error data type" << endl;
            return {1, 1, 1};
        } else {
            Costyl c{};
            c.a = a;
            int b = a;
            c.b = b;
            c.result = this->name.length();
            return c;
        }
    }

protected:
    string name;
    string surname;
    string patronymic;
    string birthdate;
    vector<string> personData = {};
};
