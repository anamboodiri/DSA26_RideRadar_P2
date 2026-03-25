#pragma once
#include <vector>
#include "Car.h"
#include "UserPreferences.h"

using namespace std;

class Filter {
public:
    static vector<Car> applyFilters(const vector<Car>& cars, const UserPreferences& prefs);
};