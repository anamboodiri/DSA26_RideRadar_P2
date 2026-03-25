#ifndef SORTING_H
#define SORTING_H
#include <vector>
#include "ScoredCar.h"
using namespace std;

bool betterCar(const ScoredCar& a, const ScoredCar& b);

void MergeSort(vector<ScoredCar>& cars, int left, int right);
void cycleSort(vector<ScoredCar>& cars);

#endif