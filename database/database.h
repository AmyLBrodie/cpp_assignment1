/* 
 * Author: Amy Brodie (BRDAMY004)
 * CSC3022H Tutorial 1
 * Created on 27 February 2016, 12:21 PM
 */


#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <vector>

namespace BRDAMY004{
    
    struct StudentRecord{
        std::string Name;
        std::string Surname;
        std::string StudentNo;
        std::string ClassRecord;
    };
    
    class StudentDatabase{
    private:
        std::vector<StudentRecord> students;
    public:
        StudentDatabase();
        void StartDatabase();
        std::string GetStudentNo();
        void AddStudent();
        void ReadDatabase();
        void SaveDatabase();
        void QueryStudent();
        void GradeStudent();
        std::string PrintRecord(StudentRecord record);
    };
    
}


#endif /* DATABASE_H */

