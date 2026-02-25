#include <iostream>
#include <string>
#include <vector>
#include "ClsCourse.h"
#include "ClsStudent.h"
using namespace std;

#ifndef CLSStudentCOURSE_H
#define CLSStudentCOURSE_H

class ClsStudentCourses
{
private :
    
    string CourseName;
    string StudentName;
    float Grade=0;

public :

    void SetCourseName(string name)
    {
        CourseName=name;
    }
    string GetCourseName()
    {
        return CourseName;
    }
    void SetStudentName(string name)
    {
        StudentName=name;
    }
    string GetStudentName()
    {
        return StudentName;
    }
    void SetGrade(float grade)
    {
        Grade=grade;
    }
    float GetGrade()
    {
        return Grade;
    }

    bool DoesStudentExist(string name , vector<ClsStudent> &students)
    {
        for (int i=0;i<students.size();i++)
        {
            if (students[i].GetName() == name)
            {
                return true;
            } 
        }
        return false;
    }
    bool DoesCourseExist(string name , vector<ClsCourse> &courses)
    {
        for (int i=0;i<courses.size();i++)
        {
            if (courses[i].GetCourseName() == name)
            {
                return true;
            } 
                
        }
        return false;
    }
    bool Does_Student_Exist_In_Student_Course_Vector(string student_name,string course_name,vector<ClsStudentCourses> &student_course_vector)
    {
        for (int i=0;i<student_course_vector.size();i++) 
        {
            if (student_course_vector[i].GetStudentName() == student_name && student_course_vector[i].GetCourseName() == course_name) return true;
        }
        return false;
    }
    void EnrollStudent(string student_name ,string course_name,vector<ClsStudentCourses> &student_course_vector)
    {
        ClsStudentCourses student_course;    
        // set names
        student_course.SetCourseName(course_name);
        student_course.SetStudentName(student_name);
        // push the student_course object
        student_course_vector.push_back(student_course);
        cout << "student enrolled successfully"<<endl;
        
    }
    void ShowCourseStudents(string course_name,vector<ClsStudentCourses> &student_course_vector)
    {
        for (int i = 0 ; i < student_course_vector.size() ; i++)
        {
            if (student_course_vector[i].GetCourseName() == course_name)
            {
                cout<<" student name is   "<<student_course_vector[i].GetStudentName()<<"   and his grade is    "
                <<student_course_vector[i].GetGrade()<<endl;
                
            }
        }
        return;
    }
    void ShowStudentCourses(string student_name,vector<ClsStudentCourses> &student_course_vector)
    {
        bool found=false;
        for (int i = 0 ; i < student_course_vector.size() ; i++)
        {
            if (student_course_vector[i].GetStudentName() == student_name)
            {
                cout<<"course |  "
                    <<student_course_vector[i].GetCourseName()
                    <<"      Grade |   "
                    <<student_course_vector[i].GetGrade()<<endl;
                    found=true;
            }
        }
        if (found==false) 
        {
            cout<<"no student found"<<endl;
        }
        return;
    }
    void ShowStudentGrade(string student_name,string course_name,vector<ClsStudentCourses> &student_course_vector)
    {
        for (int i = 0 ; i < student_course_vector.size() ; i++)
        {
            if (student_course_vector[i].GetStudentName() == student_name && student_course_vector[i].GetCourseName() == course_name) 
            {
                 cout<<"grade is |   "<<student_course_vector[i].GetGrade()<<endl;;
            }        
        }
    }
    void ChangeStudentGrade(string student_name,string course_name,float grade,vector<ClsStudentCourses> &student_course_vector)
    {
        for (int i = 0 ; i < student_course_vector.size() ; i++)
        {
            if (student_course_vector[i].GetStudentName() == student_name && student_course_vector[i].GetCourseName() == course_name) 
            {
                student_course_vector[i].SetGrade(grade);
                cout << "grade set successfully"<<endl;
                return;
            }        
        }

    }
};

#endif