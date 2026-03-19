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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    Utils ut;

    MenuItem::MenuItem(const char* content,
        unsigned int indent,
        unsigned int indentSize,
        unsigned int row)
    {
        text = nullptr;
        ind = indent;
        indSize = indentSize;
        indexOfRow = row;

        if (content) {
            text = new char[strlen(content) + 1];
            strcpy(text, content);
        }
    }

    MenuItem::~MenuItem() {
        delete[] text;
    }

    MenuItem::operator bool() const {
        return text != nullptr;
    }

    ostream& MenuItem::display(ostream& ostr) const {

        if (!(*this)) {
            return ostr; 
        }

        for (unsigned int i = 0; i < ind * indSize; i++)
            ostr << ' ';

        if (indexOfRow > 0) {
            ostr.width(2);
            ostr << indexOfRow << "- ";
        }
        else if (indexOfRow == 0) {
            ostr.width(2);
            ostr << 0 << "- ";
        }

        ostr << text;

        return ostr;
    }

    Menu::Menu(const char* title,
        const char* exitOption,
        unsigned int indent,
        unsigned int indentSize)
        : h1(title, indent, indentSize, -1),
          exit(exitOption, indent, indentSize, 0),
          intput("> ", indent, indentSize, -1)
    {
        ind = indent;
        indSize = indentSize;
        items = 0;

        for (unsigned int i = 0; i < MaximumNumberOfMenuItems; i++)
            attributes[i] = nullptr;
    }

    Menu::~Menu() {
        for (unsigned int i = 0; i < items; i++) {
            delete attributes[i];
            attributes[i] = nullptr;
        }
    }

    Menu& Menu::operator<<(const char* content) {

        if (items < MaximumNumberOfMenuItems) {

            attributes[items] =
                new MenuItem(content, ind, indSize, items + 1);

            items++;
        }

        return *this;
    }

    size_t Menu::select() const {

        if (h1)
            h1.display(cout) << endl;

        for (unsigned int i = 0; i < items; i++) {
            attributes[i]->display(cout) << endl;
        }

        exit.display(cout) << endl;

        intput.display(cout);

        return ut.getInt(0, items);
    }

    size_t operator<<(ostream& ostr, const Menu& m) {

        if (&ostr == &cout)
            return m.select();

        return 0;
    }

}
