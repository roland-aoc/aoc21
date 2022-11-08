#include <fstream>

#include "meter.h"

Meter::Meter(/* args */)
{
}

Meter::~Meter()
{
}

void Meter::run() {
    vector<int> input = read("C:\\Users\\R\\Desktop\\aoc21\\01\\input"); // . or \\ not working
    int answer = 0;
    int inc = cntInc(input);
    cout << inc << "\n";
}

vector<int> Meter::read(string path) {
  string line;
  auto readVector = vector<int> {};
  ifstream inputFile (path);
  if (inputFile.is_open()) {
    while (getline(inputFile, line))
      readVector.push_back(stoi(line));
  }
  inputFile.close();
  return readVector;
}

vector<int> Meter::calcChg(vector<int> input) {
    vector<int> chg {};
    for (int i = 0; i < input.size(); ++i) {
      // if (i == 0)
      //   continue;
      if (i == (input.size() - 1) ) break;
      chg.push_back(input[i+1] - input[i]);
    }
    return chg;
}

int Meter::cntInc(vector<int> input) {
  signed int inc = 0;
  for (int i = 0; i < input.size(); ++i) {
    if (i == input.size() - 1) break;
    if (input[i] < input[i+1]) ++inc;
  }
  return inc;
}