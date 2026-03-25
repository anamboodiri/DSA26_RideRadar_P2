#include "UI.h"
#include <iostream>
#include <limits>

using namespace std;

void UI::displayWelcomeMessage() {
    cout << "==========================================" << endl;
    cout << "         Welcome to RideRadar" << endl;
    cout << " Find the best used car for your needs." << endl;
    cout << "==========================================" << endl << endl;
}

Preferences UI::getUserPreferences() {
    Preferences prefs;

    cout << "Enter manufacturer (or leave blank): ";
    getline(cin, prefs.manufacturer);

    cout << "Enter model (or leave blank): ";
    getline(cin, prefs.model);

    string min;
    cout << "Enter minimum year: ";
    getline(cin, min);
    if (min.empty()) {
        prefs.minYear = 0;
    }
    else {
        prefs.minYear = stoi(min);
    }

    string max;
    cout << "Enter maximum year: ";
    getline(cin, max);
    if (max.empty()) {
        prefs.maxYear = 999999;
    }
    else {
        prefs.maxYear = stoi(max);
    }

    string minMile;
    cout << "Enter minimum mileage: ";
    getline(cin, minMile);
    if (minMile.empty()) {
        prefs.minMileage = 0;
    }
    else {
        prefs.minMileage = stoi(minMile);
    }

    string maxMile;
    cout << "Enter maximum mileage: ";
    getline(cin, maxMile);
    if (maxMile.empty()) {
        prefs.maxMileage = 999999;
    }
    else {
        prefs.maxMileage = stoi(maxMile);
    }

    cout << "Enter transmission (or leave blank): ";
    getline(cin, prefs.transmission);

    cout << "Enter drivetrain (or leave blank): ";
    getline(cin, prefs.drivetrain);

    string minPrice;
    cout << "Enter minimum price: ";
    getline(cin, minPrice);
    if (minPrice.empty()) {
        prefs.minPrice = 0;
    }
    else {
        prefs.minPrice = stod(minPrice);
    }

    string maxPrice;
    cout << "Enter maximum price: ";
    getline(cin, maxPrice);
    if (maxPrice.empty()) {
        prefs.maxPrice = 999999;
    }
    else {
        prefs.maxPrice = stod(maxPrice);
    }

    return prefs;
}

void UI::displayFilteredResultsCount(int count) {
    cout << endl;
    cout << "Number of matching vehicles found: " << count << endl;
    cout << "------------------------------------------" << endl;
}