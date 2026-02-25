#include <iostream>
#include <string>
#include <vector>

using namespace std;



#ifndef CLSCOURSE_H
#define CLSCOURSE_H

class ClsCourse
{
private :
    int Id;
    string CourseName;
    string InstructorName;
public :

    // get and set 
    
    // id
    void SetId(int id)
    {
        Id=id;
    }
    int GetId()
    {
        return Id;
    }
    // course name
    void SetCourseName(string name)
    {
        CourseName=name;
    }
    string GetCourseName()
    {
        return CourseName;
    }
    // instructor name
    void SetInstructorName(string name)
    {
        InstructorName=name;
    }
    string GetInstructorName()
    {
        return InstructorName;
    }

    // *****************************

    void DisplayCourses(vector<ClsCourse> &courses)
    {
        cout<<"-------------------------------"<<endl;
        for (int i=0 ; i<courses.size(); i++)
        {
            cout<<"id is "<<courses[i].GetId()<<"       course's name is        "<<courses[i].GetCourseName()<< 
            "      Instructor Name is     "<<courses[i].GetInstructorName()<<endl;
        }
       cout<<"-------------------------------"<<endl;
    }
    void AddCourse(int &next_course_id,vector<ClsCourse> &courses)
    {
        ClsCourse newcourse;
        newcourse.SetId(next_course_id++);

        cout<<"write the course's name"<<endl;
        string course_name;
        getline(cin >> ws, course_name);

        newcourse.SetCourseName(course_name);

        cout<<"write the instructor name"<<endl;
        string instructor_name;
        getline(cin >> ws, instructor_name);

        newcourse.SetInstructorName(instructor_name);

        courses.push_back(newcourse);
        cout<<"course added"<<endl;

    }
    void EditCourse(vector<ClsCourse> &courses)
    {
        cout<<"write the name"<<endl;
        string name;
        getline(cin >> ws, name);

        cout<<"write the new name"<<endl;
        string newname;
        getline(cin >> ws, newname);

        int index = FindCourseIndex(name,courses);
        
        if (index != -1 )
        {
            courses[index].SetCourseName(newname);
            cout<<"name edited"<<endl;
        } else {cout << "name not found write an existing name";}
    }
    void DeleteCourse(vector<ClsCourse> &courses)
    {
        cout<<"write the name"<<endl;
        string name;
        getline(cin >> ws, name);
        
        int index = FindCourseIndex(name,courses);
        if (index != -1)
        {
            courses.erase(courses.begin() + index);
            cout<<"course erased successfully"<<endl;
        }else {cout<<"course was not found write an existing name"<<endl;}
    }
    int FindCourseIndex(string name , vector <ClsCourse> &courses)
    {
        for (int i = 0 ; i < courses.size() ; i++)
        {
            if (courses[i].GetCourseName() == name)
            {
                return i;
            }
        }
        return -1;
    }
};

#endif