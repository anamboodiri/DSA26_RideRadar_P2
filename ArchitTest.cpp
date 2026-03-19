#include <iostream>
#include "DatasetLoader.h"

using namespace std;

int main() {
    vector<Car> cars = DatasetLoader::loadCSV("../resources/Data/carsEdit.csv");

    cout << "Cars loaded: " << cars.size() << endl;

    if (!cars.empty()) {
        cout << cars[0].manufacturer << " | "
             << cars[0].model << " | "
             << cars[0].year << " | "
             << cars[0].mileage << " | "
             << cars[0].transmission << " | "
             << cars[0].drivetrain << " | "
             << cars[0].mpg_range << " | "
             << cars[0].price << endl;
    }

    return 0;
}