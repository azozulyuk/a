/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 2:2
Module: 2
Filename: Menu.cpp
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
2026/03/16  Ready to go
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Menu.h"
#include "Utils.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

namespace seneca {

    Utils ut;

#include <cstring>  

    MenuItem::MenuItem(const char* content,
        unsigned int indent,
        unsigned int indentSize,
        unsigned int row) {

        if (content) {
            text = new char[strlen(content) + 1];
            strcpy((char*)text, content);
        }

        ind = indent;
        indSize = indentSize;
        indexOfRow = row;


    }
    MenuItem::~MenuItem() {
        delete[] text;
    }
    // display MenuItem
    void MenuItem::display() const {
        if (text) {

            for (unsigned int i = 0; i < ind * indSize; i++) {
                cout << " ";
            }

            if (indexOfRow > 0) {
                if (indexOfRow < 10)
                    cout << " " << indexOfRow << "- ";
                else
                    cout << indexOfRow << "- ";
            }
            else {
                if (ind >= 2)  
                    cout << " ";
            }

            cout << text;
        }
    }
    // Menu constructor
    Menu::Menu(const char* title,
        const char* exitOption,
        unsigned int indent,
        unsigned int indentSize)
        : h1(title, indent, indentSize, 0),
        exit(exitOption, indent, indentSize, 0),
        intput("> ", indent, indentSize, 0)
    {
        ind = indent;
        indSize = indentSize;
        items = 0;

        for (unsigned int i = 0; i < MaximumNumberOfMenuItems; i++) {
            attributes[i] = nullptr;
        }
    }

    // Destructor
    Menu::~Menu() {
        for (unsigned int i = 0; i < items; i++) {
            delete attributes[i];
            attributes[i] = nullptr;
        }
    }

    // << operator
    Menu& Menu::operator<<(const char* content) {
        if (items < MaximumNumberOfMenuItems) {

            attributes[items] =
                new MenuItem(content, ind, indSize, items + 1);

            items++;
        }
        return *this;
    }

    // select

    size_t Menu::select() const {

        // title
        h1.display();
        cout << endl;

        // menu items
        for (unsigned int i = 0; i < items; i++) {
            attributes[i]->display();
            cout << endl;
        }

        // 🔹 CORRECT EXIT POSITION
        for (unsigned int i = 0; i < ind * indSize; i++) {
            cout << " ";
        }
        cout << " " << 0 << "- " << exit.text << endl;        // prompt
        intput.display();

        int choice = ut.getInt(0, items);

        return choice;
    }

    // ostream overload
    size_t operator<<(ostream& ostr, const Menu& m) {
        if (&ostr == &cout) {
            return m.select();
        }
        return 0;
    }

}