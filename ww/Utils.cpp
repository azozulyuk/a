/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 2:2
Module: 2
Filename: Utils.cpp
-----------------------------------------------------------
Author: Anastasiya Zozulyuk
Student number: 139,230,247
Email: azozulyuk@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Date      Reason
2026/03/9  Preliminary release
2026/03/10  Debugged code
2026/03/18  Ready to go
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Utils.h"
#include <iostream>

using namespace std;

namespace seneca {

    int Utils::getInt() {
        int value;

        while (true) {
            cin >> value;

            if (cin.fail()) {
                cout << "Invalid integer: ";
                cin.clear();
            }
            else if (cin.get() != '\n') {
                cout << "Only an integer please: ";
            }
            else {
                return value;
            }

            cin.ignore(1000, '\n');
        }
    }

    int Utils::getInt(int min, int max) {
        int value;

        while (true) {
            value = getInt();

            if (value < min || value > max) {
                cout << "Invalid value: [" << min
                    << "<= value <= " << max
                    << "], try again: ";
            }
            else {
                return value;
            }
        }
    }

}