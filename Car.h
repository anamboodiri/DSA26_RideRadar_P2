#pragma once
#include <string>

using namespace std;

// Defining car object with same attributes as columns in the datasheet

struct Car {
    string manufacturer;
    string model;
    int year;
    int mileage;
    string transmission;
    string drivetrain;
    int mpg;
    double price;
    double score;
};