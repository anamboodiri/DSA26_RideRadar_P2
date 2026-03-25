#ifndef SCORING_H
#define SCORING_H
#include <vector>
#include "Car.h"
#include "Preferences.h"
#include "ScoredCar.h"
using namespace std;

void normalizeWeights(Preferences& prefs);
vector<ScoredCar> scoreCars(const vector<Car>& cars, const Preferences& prefs);

#endif