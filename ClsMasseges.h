#include <iostream>
#include <string>
#include <vector>

#ifndef MASSEGES_H
#define MASSEGES_H
using namespace std;

class ClsMasseges 
{
public :
    // main menu
    static void ShowMainMenu ()
    {
        system ("clear");
        cout<< "*****************************************"<<endl;
        cout << "===== Course Management System =====\n";
        cout << "write 1 to manage Student\n";
        cout << "write 2 to manage courses \n";
        cout << "write 3 to manage studentCourses\n";
        cout << "write 4 to exit\n";
        cout<< "*****************************************"<<endl;
    }
    // student menu
    static void ShowStudentMenu()
    {
        
        cout<< "*****************************************"<<endl;
        cout << "===== StudentMenu =====\n";
        cout << "write 1 to display all Students\n";
        cout << "write 2 to add Students \n";
        cout << "write 3 to edit Students\n";
        cout << "write 4 to delete Students\n";
        cout << "write 5 to exit\n";
        cout<< "*****************************************"<<endl;
    }
    // course menu
    static void ShowCourseMenu()
    {
        
        cout<< "*****************************************"<<endl;
        cout << "===== courseMenu =====\n";
        cout << "write 1 to display courses\n";
        cout << "write 2 to add courses \n";
        cout << "write 3 to edit courses\n";
        cout << "write 4 to delete courses\n";
        cout << "write 5 to exit\n";
        cout<< "*****************************************"<<endl;
    }

    static void ShowStudentCoursesMenu()
    {
        
        cout<< "*****************************************"<<endl;
        cout << "===== StudentCoursesMenu =====\n";
        cout << "write 1 to enroll student to a course\n";
        cout << "write 2 to search for a student by name and display their courses \n";
        cout << "write 3 to search for a course by name and display it's students and their grades\n";
        cout << "write 4 to show a student's grade"<<endl;
        cout << "write 5 to change a student's grade"<<endl;
        cout << "write 6 to exit\n";
        cout<< "*****************************************"<<endl;
    }

    static void print(string msg)
    {
        cout<<msg<<endl;
    }
    
    
    
};
#endif