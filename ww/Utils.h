/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 2:2
Module: 2
Filename: Utils.h
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
#pragma once
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

#include <iostream>

namespace seneca {

    class Utils {
    public:

        char* alocpy(const char* src) const;
        char* alocpy(char*& des, const char* src) const;

        char* strcpy(char* des, const char* src) const;

        int strlen(const char* str) const;

        bool isspace(char ch) const;
        bool isspace(const char* cstring) const;

        int getInt();
        int getInt(int min, int max);

    };

    extern Utils ut;

}

#endif