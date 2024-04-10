#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include "json.hpp"
#include <random>
#include <ctime>
#include <limits>
#include <cmath>
using namespace std;
using json = nlohmann::json;

vector <pair<pair<int, float>, int> > func(unordered_map<float, pair<int,int>>& array, int maxNum);

bool openAndReadFile(string way, unordered_map<float, pair<int,int>>& freqMap, int& maxNum, vector <string>& catchErrors);