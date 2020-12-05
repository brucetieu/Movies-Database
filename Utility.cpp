//
// Created by Bruce Tieu on 12/4/20.
//

#include "Utility.h"
#include <string>
#include <iostream>

using namespace std;

string Utility::convertToLowerCase(const string &input) {
    string tempStr = input;
    transform(tempStr.begin(), tempStr.end(), tempStr.begin(), ::tolower);

    return tempStr;
}
