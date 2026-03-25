#ifndef PREFERENCES_H
#define PREFERENCES_H
#include <string>
using namespace std;

struct UserPreferences {
    int maxPrice = 1000000; //Not storing real values(Unless Empty), just placeholders for the weights
    int maxMileage = 1000000;

    string make = "";
    string model = "";
    string transmission = "";
    string drivetrain = "";

    double priceW = 1.0; //ALL WEIGHTS
    double mileageW = 1.0;
    double mpgW = 1.0;
    double yearW = 1.0;
};



#endif
