//
// Created by Ahan Soni on 3/20/26.
//

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

UserPreferences UI::getUserPreferences() {
    UserPreferences prefs;

    cout << "Enter manufacturer (or leave blank): ";
    getline(cin, prefs.manufacturer);

    cout << "Enter model (or leave blank): ";
    getline(cin, prefs.model);

    cout << "Enter minimum year: ";
    cin >> prefs.minYear;

    cout << "Enter maximum year: ";
    cin >> prefs.maxYear;

    cout << "Enter minimum mileage: ";
    cin >> prefs.minMileage;

    cout << "Enter maximum mileage: ";
    cin >> prefs.maxMileage;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter transmission (or leave blank): ";
    getline(cin, prefs.transmission);

    cout << "Enter drivetrain (or leave blank): ";
    getline(cin, prefs.drivetrain);

    cout << "Enter minimum price: ";
    cin >> prefs.minPrice;

    cout << "Enter maximum price: ";
    cin >> prefs.maxPrice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return prefs;
}

void UI::displayFilteredResultsCount(int count) {
    cout << endl;
    cout << "Number of matching vehicles found: " << count << endl;
    cout << "------------------------------------------" << endl;
}
