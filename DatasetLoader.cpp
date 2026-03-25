#include "DatasetLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

// This file Loads all cars from the dataset and parses each row into the Car Object,
// All the cars are stored in vector for filtering and sorting



using namespace std;

vector<Car> DatasetLoader::loadCSV(const string& filepath) {
    vector<Car> cars;
    cars.reserve(750000);

    ifstream file(filepath);

    if (!file.is_open()) {
        cout << "ERROR: Could not open file." << endl;
        return cars;
    }

    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        Car car;

        try {
            getline(ss, car.manufacturer, ',');
            getline(ss, car.model, ',');

            getline(ss, token, ',');
            car.year = stoi(token);

            getline(ss, token, ',');
            token.erase(remove(token.begin(), token.end(), ','), token.end());
            car.mileage = stoi(token);

            getline(ss, car.transmission, ',');
            getline(ss, car.drivetrain, ',');

            getline(ss, token, ',');
            car.mpg = stoi(token);

            getline(ss, token, ',');
            car.price = stod(token);

            car.score = 0.0;
            cars.push_back(car);
        } catch (...) {
            continue;
        }
    }

    file.close();
    return cars;
}