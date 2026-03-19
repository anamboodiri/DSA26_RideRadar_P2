#pragma once
#include <vector>
#include <string>
#include "Car.h"

using namespace std;

class DatasetLoader {
public:
    static vector<Car> loadCSV(const string& filepath);
};