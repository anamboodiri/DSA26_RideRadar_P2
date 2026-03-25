#include "Scoring.h"
using namespace std;

void normalizeWeights(Preferences& prefs) {
    double total = prefs.priceW + prefs.mileageW + prefs.mpgW + prefs.yearW;

    if (total == 0.0) {
        prefs.priceW = 0.25;
        prefs.mileageW = 0.25;
        prefs.mpgW = 0.25;
        prefs.yearW = 0.25;
        return;
    }

    prefs.priceW /= total;
    prefs.mileageW /= total;
    prefs.mpgW /= total;
    prefs.yearW /= total;
}

vector<ScoredCar> scoreCars(const vector<Car>& cars, const Preferences& prefs) {
    vector<ScoredCar> scoredCars;

    if (cars.empty()) return scoredCars;

    double minPrice = cars[0].price;
    int minMileage = cars[0].mileage;
    int maxMPG = cars[0].mpg;
    int minYear = cars[0].year;
    int maxYear = cars[0].year;

    for (const Car& car : cars) {
        if (car.price < minPrice) minPrice = car.price;
        if (car.mileage < minMileage) minMileage = car.mileage;
        if (car.mpg > maxMPG) maxMPG = car.mpg;
        if (car.year < minYear) minYear = car.year;
        if (car.year > maxYear) maxYear = car.year;
    }

    for (const Car& car : cars) {
        double priceScore = (car.price == 0) ? 0.0 : minPrice / car.price;
        double mileageScore = (car.mileage == 0) ? 0.0 : double(minMileage) / car.mileage;
        double mpgScore = (maxMPG == 0) ? 0.0 : double(car.mpg) / maxMPG;
        double yearScore = 1.0;

        if (maxYear != minYear) {
            yearScore = double(car.year - minYear) / (maxYear - minYear);
        }

        double totalScore =
            priceScore * prefs.priceW +
            mileageScore * prefs.mileageW +
            mpgScore * prefs.mpgW +
            yearScore * prefs.yearW;

        ScoredCar scoredCar;
        scoredCar.car = car;
        scoredCar.score = totalScore;

        scoredCars.push_back(scoredCar);
    }

    return scoredCars;
}