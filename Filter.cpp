#include "Filter.h"
using namespace std;

vector<Car> filterCars(const vector<Car>& cars, const UserPreferences& prefs) {
    vector<Car> filtered;

    for (const Car& car : cars) {
        if (car.price > prefs.maxPrice) continue; //Completely Removes Cars over max price
        if (car.mileage > prefs.maxMileage) continue; //Completely Removes Cars over max mileage

        if (!prefs.make.empty() && car.make != prefs.make) continue;
        if (!prefs.model.empty() && car.model != prefs.model) continue;
        if (!prefs.transmission.empty() && car.transmission != prefs.transmission) continue;
        if (!prefs.drivetrain.empty() && car.drivetrain != prefs.drivetrain) continue;

        //^^Remove any Make, Model, Trans., and Drivetrain that doesn't match the user input

        filtered.push_back(car); //If the car survives it enters the filtered vector
    }

    return filtered;
}