#include "Sorting.h"
#include <utility>
using namespace std;

bool betterCar(const ScoredCar& a, const ScoredCar& b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }                                    //Tie Breaker checks, hierarchy from score->price->mileage->year
    if (a.car.price != b.car.price) {
        return a.car.price < b.car.price;
    }
    if (a.car.mileage != b.car.mileage) {
        return a.car.mileage < b.car.mileage;
    }
    return a.car.year > b.car.year;
}

static void merge(vector<ScoredCar>& cars, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<ScoredCar> leftPart(n1);
    vector<ScoredCar> rightPart(n2);

    for (int i = 0; i < n1; i++) {
        leftPart[i] = cars[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightPart[j] = cars[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (betterCar(leftPart[i], rightPart[j])) {
            cars[k++] = leftPart[i++];
        } else {
            cars[k++] = rightPart[j++];
        }
    }

    while (i < n1) cars[k++] = leftPart[i++];
    while (j < n2) cars[k++] = rightPart[j++];
}

void mergeSort(vector<ScoredCar>& cars, int left, int right) { //It's expected that merge sort
    if (left >= right) {                               //Will perform marginally better O(nlogn)
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(cars, left, mid);
    mergeSort(cars, mid + 1, right);
    merge(cars, left, mid, right);
}

void cycleSort(vector<ScoredCar>& cars) {   //Known to be pretty bad with large inputs, SHOULD be slower
    int n = static_cast<int>(cars.size());                    //O(n^2) here

    for (int cycleStart = 0; cycleStart <= n - 2; cycleStart++) {
        ScoredCar item = cars[cycleStart];
        int pos = cycleStart;

        for (int i = cycleStart + 1; i < n; i++) {
            if (betterCar(cars[i], item)) {
                pos++;
            }
        }

        if (pos == cycleStart) {
            continue;
        }

        while (pos < n && !betterCar(item, cars[pos]) && !betterCar(cars[pos], item)) {
            pos++;
        }

        if (pos < n) {
            swap(item, cars[pos]);
        }

        while (pos != cycleStart) {
            pos = cycleStart;

            for (int i = cycleStart + 1; i < n; i++) {
                if (betterCar(cars[i], item)) {
                    pos++;
                }
            }

            while (pos < n && !betterCar(item, cars[pos]) && !betterCar(cars[pos], item)) {
                pos++;
            }

            if (pos < n) {
                swap(item, cars[pos]);
            }
        }
    }
}