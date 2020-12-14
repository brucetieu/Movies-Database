//
// Created by Bruce Tieu on 12/4/20.
//

#include "Utility.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Convert a sting to all loweraase.
 * @param input The string to be converted.
 * @return The string in all lowercase.
 */
string Utility::convertToLowerCase(const string &input) {
    string tempStr = input;
    transform(tempStr.begin(), tempStr.end(), tempStr.begin(), ::tolower);

    return tempStr;
}
