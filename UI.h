//
// Created by Ahan Soni on 3/20/26.
//
#pragma once
#include "UserPreferences.h"

using namespace std;

class UI {
public:
    static UserPreferences getUserPreferences();
    static void displayWelcomeMessage();
    static void displayFilteredResultsCount(int count);
};