//
// Created by rustam on 29.03.25.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class AbstractOne {
    public:
    virtual ~AbstractOne() = default;

    virtual vector<string> getPersonData() {
        return {};
    };
};

