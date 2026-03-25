//
// Created by Ahan Soni on 3/20/26.
//
#pragma once
#include <string>

using namespace std;
//stores all user filters and their respective weights
struct Preferences {
    string manufacturer;
    string model;

    int minYear;
    int maxYear;

    int minMileage;
    int maxMileage;

    string transmission;
    string drivetrain;

    double minPrice;
    double maxPrice;

    double priceW = 1.0;
    double mileageW = 1.0;
    double mpgW = 1.0;
    double yearW = 1.0;
};