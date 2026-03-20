//
// Created by Ahan Soni on 3/20/26.
//
#pragma once
#include <string>

using namespace std;

struct UserPreferences {
    string manufacturer;
    string model;

    int minYear;
    int maxYear;

    int minMileage;
    int maxMileage;

    string transmission;
    string drivetrain;
