#include <iostream>
#include <string>
#include <vector>

using namespace std;
#ifndef CLSSTUDENT_H
#define CLSSTUDENT_H
class ClsStudent
{
private : 
    string Name;
    int Id;
public :
    // get and set
    void SetName(string name)
    {
        Name = name;
    }
    string GetName()
    {
        return Name;
    }
    void SetId (int id)
    {
        Id=id;
    }
    int GetId()
    {
        return Id;
    }
    // *********************
    
    void DisplayStudents(vector <ClsStudent> &students)
    {
       cout<<"-------------------------------"<<endl;
        for (int i=0 ; i<students.size(); i++)
        {
            cout<<"id is "<<students[i].GetId()<<"    name is "<<students[i].GetName()<<endl;
        }
       cout<<"-------------------------------"<<endl;
        
    }
    void AddStudent(int &next_student_id,vector <ClsStudent> &students)
    {
        ClsStudent newstudent;
        newstudent.SetId(next_student_id++);

        cout<<"write the name"<<endl;
        string name;
        getline(cin >> ws, name);

        newstudent.SetName(name);
        students.push_back(newstudent);
        cout<<"student added"<<endl;

    }

    int FindStudentIndex(string name , vector <ClsStudent> &students)
    {
        for (int i = 0 ; i < students.size() ; i++)
        {
            if (students[i].GetName() == name)
            {
                return i;
            }
        }
        return -1;
    }
    void EditStudent(vector <ClsStudent> &students)
    {
        cout<<"write the name"<<endl;
        string name;
        getline(cin >> ws, name);

        cout<<"write the new name"<<endl;
        string newname;
        getline(cin >> ws, newname);

        int index = FindStudentIndex(name,students);
        
        if (index != -1 )
        {
            students[index].SetName(newname);
            cout<<"name edited"<<endl;
        } else {cout << "name not found write an existing name";}
    }
    void DeleteStudent(vector <ClsStudent> &students)
    {
        cout<<"write the name"<<endl;
        string name;
        getline(cin >> ws, name);
        
        int index = FindStudentIndex(name,students);
        if (index != -1)
        {
            students.erase(students.begin() + index);
            cout<<"student erased successfully"<<endl;
        }else {cout<<"student was not found write an existing name"<<endl;}
        
    }

};
#endif