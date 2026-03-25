#pragma once
#include <vector>
#include "Car.h"
#include "Preferences.h"

using namespace std;

class Filter {
public:
    static vector<Car> applyFilters(const vector<Car>& cars, const Preferences& prefs);
};