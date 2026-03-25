#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "DatasetLoader.h"
#include "Filter.h"
#include "UI.h"
#include "Preferences.h"
#include "Car.h"
#include "Scoring.h"
#include "Sorting.h"
#include "ScoredCar.h"

using namespace std;
using namespace chrono;

void displayTopMatches(const vector<ScoredCar>& cars, int limit) {
    int displayCount = min((int)cars.size(), limit);

    if (displayCount == 0) {
        cout << "No matching vehicles found." << endl;
        return;
    }

    for (int i = 0; i < displayCount; i++) {
        cout << i + 1 << ". "
             << cars[i].car.manufacturer << " | "
             << cars[i].car.model << " | "
             << cars[i].car.year << " | "
             << cars[i].car.mileage << " miles | "
             << cars[i].car.transmission << " | "
             << cars[i].car.drivetrain << " | MPG: "
             << cars[i].car.mpg << " | $"
             << cars[i].car.price
             << " | Score: " << cars[i].score
             << endl;
    }
}

int main() {
    UI::displayWelcomeMessage();

    cout << "Loading vehicle dataset..." << endl;
    vector<Car> allCars = DatasetLoader::loadCSV("../resources/Data/carsEdit.csv");
    cout << "Cars loaded: " << allCars.size() << endl << endl;

    Preferences prefs = UI::getUserPreferences();
    normalizeWeights(prefs);

    vector<Car> filteredCars = Filter::applyFilters(allCars, prefs);

    UI::displayFilteredResultsCount((int)filteredCars.size());

    vector<ScoredCar> scoredCars = scoreCars(filteredCars, prefs);

    if (scoredCars.empty()) {
        cout << "No matching vehicles found." << endl;
        return 0;
    }

    vector<ScoredCar> mergeCars = scoredCars;
    vector<ScoredCar> cycleCars = scoredCars;

    auto mergeStart = high_resolution_clock::now();
    mergeSort(mergeCars, 0, (int)mergeCars.size() - 1);
    auto mergeEnd = high_resolution_clock::now();

    auto cycleStart = high_resolution_clock::now();
    cycleSort(cycleCars);
    auto cycleEnd = high_resolution_clock::now();
    //“std::chrono.” cppreference.com, https://en.cppreference.com/w/cpp/chrono.
   //^Citation for how to use clock timing

    auto mergeDuration = duration_cast<microseconds>(mergeEnd - mergeStart);
    auto cycleDuration = duration_cast<microseconds>(cycleEnd - cycleStart);

    cout << "\n===== Merge Sort Top 10 Matches =====" << endl << endl;
    displayTopMatches(mergeCars, 10);
    cout << "\nMerge Sort Time: " << mergeDuration.count() << " microseconds" << endl;

    cout << "\n===== Cycle Sort Top 10 Matches =====" << endl << endl;
    displayTopMatches(cycleCars, 10);
    cout << "\nCycle Sort Time: " << cycleDuration.count() << " microseconds" << endl;

    return 0;
}