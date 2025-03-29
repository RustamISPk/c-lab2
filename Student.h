#pragma once
#include <cstring>
#include <iostream>
#include <string>
#include "Person.h"
#include "AbstractTwo.h"

using namespace std;

class Student : Person, public AbstractTwo {
public:
    //Person(string name, string surname, string patronymic, string birthdate);
    Student(string name, string surname, string patronymic, string birthdate, string group) : Person(name,
        surname,
        patronymic,
        birthdate) {
        this->group = group;
        this->attendanceMatrix = (int **) malloc(4 * sizeof(int *));
        for (int i = 0; i < 4; i++) {
            attendanceMatrix[i] = (int *) malloc(100 * sizeof(int));
            memset(attendanceMatrix[i], 0, 100 * sizeof(int)); // Инициализация нулями
        }
    }

    vector<string> getPersonData() override{
        // Person::getPersonData();
        this->personData.push_back(this->name);
        this->personData.push_back(this->surname);
        this->personData.push_back(this->patronymic);
        this->personData.push_back(this->group);
        this->personData.push_back(this->birthdate);
        return this->personData;
    };

    Student *pushMarks(int mark) {
        this->marks.push_back(mark);
        return this;
    }

    template<typename T>
    double avgMarks(T sum, double avg) {
        if constexpr (is_same_v<T, char>) {
            cout << "Error data type" << endl;
            return 1;
        } else {
            for (int i = 0; i < this->marks.size(); i++) {
                sum += this->marks[i];
            }
            avg = sum / this->marks.size();
            return avg;
        }
    }

    vector<int> getMarks() override{
        return this->marks;
    }

    Student *pushAttendance(int x, int y, int attendance) {
        this->attendanceMatrix[x][y] = attendance;
        return this;
    }

    int getAttendance(int x, int y) {
        return this->attendanceMatrix[x][y];
    }

protected:
    string group;
    vector<int> marks;
    // string subjects [] = {"биология", "химия", "математика", "информатика"};
    int **attendanceMatrix;
};
