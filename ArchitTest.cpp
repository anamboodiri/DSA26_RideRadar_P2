#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("resources/Data/carsEdit.csv");

    if (!file.is_open()) {
        cout << "FAILED TO OPEN CSV" << endl;
        return 1;
    }

    cout << "CSV OPENED SUCCESSFULLY\n\n";

    string line;
    int count = 0;

    while (getline(file, line) && count < 5) {
        cout << "LINE " << count + 1 << " length = " << line.length() << endl;
        cout << "[" << line << "]" << endl << endl;
        count++;
    }

    file.close();
    return 0;
}