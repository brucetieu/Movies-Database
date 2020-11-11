//
// Created by Bruce Tieu on 11/10/20.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Database.h"
#include "Pictures.h"
#include "ActorsActresses.h"

using namespace std;

int main()
{
    Database *database1;
    Database *database2;

    Pictures pictures;
    ActorsActresses actorsActresses;

    database1 = &pictures;
    database1->readInFile();

    database2 = &actorsActresses;
    database2->readInFile();
//    ifstream infile("actor-actress.csv");
//    string header,year,award, winner, name, film;
//    int records = 0;
//
//    getline(infile, header);
//    cout << "Header\n" << header << endl << endl;
//    while (infile.good())
//    {
//        getline(infile, year, ',');
//        getline(infile,award, ',');
//        getline(infile, winner, ',');
//        getline(infile, name, ',');
//        getline(infile,film);
//        cout << year << endl << award << endl << winner <<endl << name <<endl<<film<<endl;
//        records++;
//        cout << "RECORDS: " << records<<endl << endl;
//    }
//
//    cout << "Records: "<<records <<endl;


    return 0;
}