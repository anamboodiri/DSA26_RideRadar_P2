//
// Created by Ahan Soni on 3/20/26.
//

#include <iostream>
#include <vector>
#include "DatasetLoader.h"
#include "Filter.h"
#include "UI.h"
#include "UserPreferences.h"
#include "Car.h"

using namespace std;

void displayTopMatches(const vector<Car>& cars, int limit) {
    int displayCount = min((int)cars.size(), limit);

    if (displayCount == 0) {
        cout << "No matching vehicles found." << endl;
        return;
    }

    for (int i = 0; i < displayCount; i++) {
        cout << i + 1 << ". "
             << cars[i].manufacturer << " | "
             << cars[i].model << " | "
             << cars[i].year << " | "
             << cars[i].mileage << " miles | "
             << cars[i].transmission << " | "
             << cars[i].drivetrain << " | MPG: "
             << cars[i].mpg_range << " | $"
             << cars[i].price << endl;
    }
}

int main() {
    UI::displayWelcomeMessage();

    cout << "Loading vehicle dataset..." << endl;
    vector<Car> allCars = DatasetLoader::loadCSV("../resources/Data/carsEdit.csv");
    cout << "Cars loaded: " << allCars.size() << endl << endl;

    UserPreferences prefs = UI::getUserPreferences();

    vector<Car> filteredCars = Filter::applyFilters(allCars, prefs);

    UI::displayFilteredResultsCount((int)filteredCars.size());

    cout << "Showing up to 10 matching vehicles:" << endl << endl;
    displayTopMatches(filteredCars, 10);

    return 0;
}