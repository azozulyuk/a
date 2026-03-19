/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 2:2
Module: 2
Filename: Menu.h
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
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream>

namespace seneca {

    const unsigned int MaximumNumberOfMenuItems = 20;

    class Menu;

    class MenuItem {
        friend class Menu;

        const char* text{};
        unsigned int ind{};
        unsigned int indSize{};
        unsigned int indexOfRow{};

        MenuItem(const char* content = nullptr,
            unsigned int indent = 0,
            unsigned int indentSize = 3,
            unsigned int row = 0);
        ~MenuItem();
        void display() const;
    };

    class Menu {
        unsigned int ind{};
        unsigned int indSize{};
        unsigned int items{};

        MenuItem h1;
        MenuItem exit;
        MenuItem intput;

        MenuItem* attributes[MaximumNumberOfMenuItems];

    public:
        Menu(const char* title,
            const char* exitOption = "Exit",
            unsigned int indent = 0,
            unsigned int indentSize = 3);

        ~Menu();

        Menu& operator<<(const char* content);

        size_t select() const;

        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;
    };

    size_t operator<<(std::ostream& ostr, const Menu& m);

}

#endif