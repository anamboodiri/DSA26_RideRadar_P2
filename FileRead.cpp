#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Car.h"
using namespace std;


int main() {

    ifstream file("cars.csv"); // Calls to read file
    string line;

    vector<Car> cars;

    getline(file, line);

    while (getline(file, line)) { // While there is something to read

        stringstream ss(line);
        string token;

        Car car;

        getline(ss, car.make, ',');  // Saves first input to make
        getline(ss, car.model, ','); // Saves second input to model

        getline(ss, token, ','); // Saves string of the price to token
        car.year = stoi(token); // Saves token to year

        getline(ss, token, ',');
        car.mileage = stoi(token); // ^Same process^, saves token to mileage now

        getline(ss, car.transmission, ',');
        getline(ss, car.drivetrain, ',');

        getline(ss, token, ',');
        car.mpg = stoi(token);

        getline(ss, token, ',');
        car.price = stoi(token);

        cars.push_back(car); // Saves car from data file to the vector
    }
}