#include <fstream>
#include <algorithm>
// #include "bits/stdc++.h"
#include <numeric>
#include <execution>

#include "meter.h"

Meter::Meter(/* args */)
{
}

Meter::~Meter()
{
}

void Meter::run() {
    vector<int> input = read("C:\\Users\\R\\Desktop\\aoc21\\01\\input"); // . or \\ not working
    cout << cntInc(input);
}

vector<int> Meter::read(string path) {
  //refined by Item 6
  ifstream dataFile(path);
  istream_iterator<int> dataBegin(dataFile);
  istream_iterator<int> dataEnd;
  return vector<int>(dataBegin, dataEnd);
}

int Meter::cntInc(vector<int> input) {
  //refined by Item 5
  vector<int> change(input.size()-1);
  change.assign(input.begin()+1, input.end());

  return transform_reduce(
        execution::unseq, 
        change.begin(), change.end(), 
        input.begin(), 0, 
        plus<>(),//reduce
        greater<>()//transform
    ); 
}