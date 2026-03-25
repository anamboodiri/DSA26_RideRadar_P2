//
// Created by Ahan Soni on 3/20/26.
//
#pragma once
#include "Preferences.h"

using namespace std;
//handle all user interaction
class UI {
public:
    static Preferences getUserPreferences();
    static void displayWelcomeMessage();
    static void displayFilteredResultsCount(int count);
};