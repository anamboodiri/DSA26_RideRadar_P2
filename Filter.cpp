#include "Filter.h"

using namespace std;

// applyFilters filters the dataset of cars based on all criteria (manufacturer, model, minYear, maxYear, etc..)
// returns cars that only match that criteria

vector<Car> Filter::applyFilters(const vector<Car>& cars, const Preferences& prefs) {
    vector<Car> filteredCars;

    for (const Car& car : cars) {
        bool matches = true;

        if (!prefs.manufacturer.empty() && car.manufacturer != prefs.manufacturer)
            matches = false;

        if (!prefs.model.empty() && car.model != prefs.model)
            matches = false;

        if (car.year < prefs.minYear || car.year > prefs.maxYear)
            matches = false;

        if (car.mileage < prefs.minMileage || car.mileage > prefs.maxMileage)
            matches = false;

        if (!prefs.transmission.empty() && car.transmission != prefs.transmission)
            matches = false;

        if (!prefs.drivetrain.empty() && car.drivetrain != prefs.drivetrain)
            matches = false;

        if (car.price < prefs.minPrice || car.price > prefs.maxPrice)
            matches = false;

        if (matches)
            filteredCars.push_back(car);
    }

    return filteredCars;
}