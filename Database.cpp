//
// Created by Bruce Tieu on 11/10/20.
//

#include "Database.h"
#include <string>

using namespace std;

void Database::setName(string name) {this->name = name; }
void Database::setYear(string year) {this->year = year; }

string Database::getName() {
    return name;
}

string Database::getYear() {
    return year;
}