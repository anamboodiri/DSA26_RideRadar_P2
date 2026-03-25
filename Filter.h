#ifndef FILTER_H
#define FILTER_H
#include <vector>
#include "Car.h"
#include "Preferences.h"
using namespace std;

vector<Car> filterCars(const vector<Car>& cars, const UserPreferences& prefs);

#endif