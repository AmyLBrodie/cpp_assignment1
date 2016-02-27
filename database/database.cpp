/* 
 * Author: Amy Brodie (BRDAMY004)
 * CSC3022H Tutorial 1
 * Created on 27 February 2016, 12:21 PM
 */

#include "database.h"
#include <iostream>
#include <fstream>
#include <sstream>


namespace BRDAMY004{
    class StudentDatabase{
        StartDatabase(){
            std::string file = "Student_Database.txt";
            std::ifstream fileInput (file.c_str());
            if (!fileInput){
                std::cout << "Could not open file: " << file << std::endl;
                return 1;
            }

            while (!fileInput.eof()){
                std::string line;
                std::string temp;
                StudentRecord tempRecord;
                /*tempRecord.Name = "";
                tempRecord.Surname = "";
                tempRecord.StudentNo = "";
                tempRecord.ClassRecord = "";*/
                std::getline(fileInput, line, "\n");
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
                students.push_back(tempRecord);
            }

            fileInput.close();
        }

        std::string GetStudentNo(){
            std::string studentNo;
            std::cout << "Enter the student number" << std::endl;
            std::cin >> studentNo;
            return studentNo;
        }

        AddStudent(){
            StudentRecord newStudent;
            std::cout << "Enter the student's name:" << std::endl;
            std::cin >> newStudent.Name;
            std::cout << "Enter the student's surname:" << std::endl;
            std::cin >> newStudent.Surname;
            std::cout << "Enter the student number:" << std::endl;
            std::cin >> newStudent.StudentNo;
            std::cout << "Enter the student's class record (separated by spaces):" << std::endl;
            std::cin >> newStudent.ClassRecord;
        }

        ReadDatabase(){

        }
        
        SaveDatabase(){
            
        }
        
        QueryStudent(){
            
        }
        
        double GradeStudent(){
            
        }
        
        PrintRecord(StudentRecord record){
            
        }
    };
    
}
