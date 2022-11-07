#ifndef METER_H
#define METER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Meter
{
    vector<int> read(string);
    vector<int> calcChg(vector<int>);
    int cntDiff(vector<int>);

public:
    Meter(/* args */);
    ~Meter();
    void run();
};

#endif