//
// Created by rustam on 29.03.25.
//
#include <iostream>
#include <vector>
using namespace std;
class AbstractTwo {
    public:
    virtual ~AbstractTwo() = default;

    virtual vector<int> getMarks() {
            return {};
        };
};
