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
    auto chg = calcChg(input);
    int diff = cntDiff(chg);
    cout << diff << "\n";
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
      if (i == 0)
        continue;
      if (i != (input.size() - 1) )
        chg.push_back(input[i] / (input[i-1] - input[i]));
    }
    return chg;
}

int Meter::cntDiff(vector<int> chg) {
  int cnt;
  for (int i = 0; i < chg.size(); ++i) {
    if (i == chg.size() - 1) break;
    if (chg[i] < chg[i+1]) ++cnt;
  }
  return cnt;
}