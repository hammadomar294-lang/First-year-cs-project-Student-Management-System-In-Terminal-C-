#include <iostream>
#include <string>
#include <vector>


using namespace std;
#ifndef HELPER_H
#define HELPER_H

class helper
{
    public :
        static string AskForCourseName()
        {
            cout<<"write the course name"<<endl;
            string course_name;
            getline(cin >> ws, course_name);
            return course_name;
        }
        static string AskForStudentName()
        {
            cout<<"write the student name"<<endl;
            string student_name;
            getline(cin >> ws, student_name);
            return student_name;
        }
        static float AskForGrade()
        {
            float grade=-1;
            while (grade <0 || grade>100)
            {
                cout<<"write the grade"<<endl;
                cin>>grade;
                
                if (grade <0 || grade>100)
                {
                    cout<<"write a valid grade"<<endl;
                }
                
            }
            return grade;
        }
};

#endif