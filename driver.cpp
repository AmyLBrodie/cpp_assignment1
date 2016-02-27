/* 
 * Author: Amy Brodie (BRDAMY004)
 * CSC3022H Tutorial 1
 * Created on 26 February 2016
 */

#include <iostream>
#include <cstdlib>
#include "database/database.h"



int main(int argc, char** argv) {
    using namespace std;
    string choice;
    BRDAMY004::StudentDatabase studentDatabase;
    studentDatabase.StartDatabase();
    for (;;){
        cout << "0: Add Student" << endl;
        cout << "1: Read Database" << endl;
        cout << "2: Save Database" << endl;
        cout << "3: Display Given Student Data" << endl;
        cout << "4: Grade Student" << endl;
        cout << "q: Quit" << endl;
        cout << "Enter a number (or q to quit) and press return..." << endl;
        cin >> choice;
        
        system("clear");
        
        if (choice == "0"){
            cout << "function AddStudent() called\n" << endl;
            studentDatabase.AddStudent();
        }
        else if (choice == "1"){
           cout << "function ReadDatabase() called\n" << endl;
           studentDatabase.ReadDatabase();
        }
        else if (choice == "2"){
           cout << "function SaveDatabase() called\n" << endl;
           studentDatabase.SaveDatabase();
        }
        else if (choice == "3"){
           cout << "function QueryStudent() called\n" << endl;
           studentDatabase.QueryStudent();
        }
        else if (choice == "4"){
           cout << "function GradeStudent() called\n" << endl;
           studentDatabase.GradeStudent();
        }
        else if (choice == "q" or choice == "Q"){
            break;
        }
        else{
            cout << "Not a valid option" << endl;
        } 
        cout << "" << endl;
    }
    
    return 0;
}

