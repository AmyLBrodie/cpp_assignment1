/* 
 * Author: Amy Brodie (BRDAMY004)
 * CSC3022H Tutorial 1
 * Created on 27 February 2016, 12:21 PM
 */

#include "database.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>


namespace BRDAMY004{
    std::vector<StudentRecord> students;
    
    StudentDatabase::StudentDatabase(){
        
    }
    
    // Reads data out of textfile and places it inside the vector called students
    // Only called when program is started
    void StudentDatabase::StartDatabase(){
        std::string file = "Student_Database.txt";
        std::ifstream fileInput (file.c_str());
        if (!fileInput){
            std::cout << "Could not open file: " << file << std::endl;
        }

        while (!fileInput.eof()){
            std::string line;
            std::string temp;
            StudentRecord tempRecord;
            std::getline(fileInput, line, '\n');
            std::istringstream splitRecords(line);
            splitRecords >> tempRecord.Name >> tempRecord.Surname >> tempRecord.StudentNo >> tempRecord.ClassRecord;
            splitRecords >> temp;
            tempRecord.ClassRecord += " " + temp;
            temp = "";
            splitRecords >> temp;
            tempRecord.ClassRecord += " " + temp;
            temp = "";
            splitRecords >> temp;
            tempRecord.ClassRecord += " " + temp;
            // makes sure that the record is not blank
            if (tempRecord.Name != ""){
                students.push_back(tempRecord);
            }
        }

        fileInput.close();
    }

    // Takes an inputted student number, converts it to upper case and returns it
    std::string StudentDatabase::GetStudentNo(){
        std::string studentNo;
        std::cout << "Enter the student number:" << std::endl;
        std::cin >> studentNo;
        std::transform(studentNo.begin(), studentNo.end(), studentNo.begin(), toupper);
        return studentNo;
    }
    
    // Takes a StudentRecord and makes a string out of it, then returns this string
    std::string StudentDatabase::PrintRecord(StudentRecord record){
        std::string temp;
        temp = record.Name + " " + record.Surname + " " + record.StudentNo + " " + record.ClassRecord;
        return temp;
    }

    // Takes in data about a new student record
    // Checks if the student number exists in the database already
    // If it exists then the existing data is overwritten
    // If it doesn't exist then a new record is added to the database
    void StudentDatabase::AddStudent(){
        std::string grade1, grade2, grade3, grade4;
        StudentRecord newStudent;
        std::cout << "Enter the student's name:" << std::endl;
        std::cin >> newStudent.Name;
        std::cout << "Enter the student's surname:" << std::endl;
        std::cin >> newStudent.Surname;
        std::cout << "Enter the student number:" << std::endl;
        std::cin >> newStudent.StudentNo;
        std::cout << "Enter the student's first mark:"<< std::endl;
        std::cin >> grade1;
        std::cout << "Enter the student's second mark:"<< std::endl;
        std::cin >> grade2;
        std::cout << "Enter the student's third mark:"<< std::endl;
        std::cin >> grade3;
        std::cout << "Enter the student's fourth mark:"<< std::endl;
        std::cin >> grade4;
        newStudent.ClassRecord = grade1 + " " + grade2 + " " + grade3 + " " + grade4;
        bool found = false;
        std::transform(newStudent.StudentNo.begin(), newStudent.StudentNo.end(), newStudent.StudentNo.begin(), toupper);
        for (int i=0; i<students.size(); i++){
            if (students.at(i).StudentNo == newStudent.StudentNo){
                found = true;
                students.at(i).Name = newStudent.Name;
                students.at(i).Surname = newStudent.Surname;
                students.at(i).ClassRecord = newStudent.ClassRecord;
            }
        }
        if (found == false){
            students.push_back(newStudent);
        }
    }

    // Prints out the student records that are in the vector called students
    // It will print out all records in the vector (including unsaved records)
    void StudentDatabase::ReadDatabase(){
        for (int i=0; i<students.size(); i++){
            std::cout << PrintRecord(students.at(i)) << std::endl;
        }
    }

    // Takes all the student records in the vector and places them in the database textfile
    void StudentDatabase::SaveDatabase(){
        std::string file = "Student_Database.txt";
        std::ofstream fileWrite(file.c_str());
        for (int i=0; i<students.size(); i++){
            fileWrite << PrintRecord(students.at(i))<< std::endl;
        }
        fileWrite.close();
    }

    // Takes in a student number and searches the database for that student number
    // If found the students record will be displayed
    // If not found a message will be displayed to that effect
    void StudentDatabase::QueryStudent(){
        bool found = false;
        std::string studentNo = GetStudentNo();
        int position;
        for (int i=0; i<students.size(); i++){
            if (students.at(i).StudentNo == studentNo){
                found = true;
                position = i;
            }
        }
        if (found == true){
            std::cout << PrintRecord(students.at(position)) << std::endl;
        }
        else{
            std::cout << "Student not found in database" << std::endl;
        }
    }

    // Takes in a student number and searches the database for that student
    // If found the student's average grade will be calculated and displayed
    // If not found a message will be displayed to that effect
    void StudentDatabase::GradeStudent(){
        bool found = false;
        std::string studentNo = GetStudentNo();
        int grade1, grade2, grade3, grade4;
        int position;
        double average;
        for (int i=0; i<students.size(); i++){
            if (students.at(i).StudentNo == studentNo){
                found = true;
                position = i;
            }
        }
        if (found == true){
            std::istringstream classRecord(students.at(position).ClassRecord);
            classRecord >> grade1;
            classRecord >> grade2;
            classRecord >> grade3;
            classRecord >> grade4;
            average = (grade1 + grade2 + grade3 + grade4)/4.0;
            std::cout << "The average of " << studentNo << " is: " << average << std::endl;
        }
        else{
            std::cout << "Student not found in database" << std::endl;
        }
    }

    
    
}
