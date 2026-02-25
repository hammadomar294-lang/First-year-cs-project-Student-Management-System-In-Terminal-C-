#include <iostream>
#include <string>
#include <vector>

#include "ClsMasseges.h"
#include "ClsStudent.h"
#include "ClsCourse.h"
#include "ClsStudentCourses.h"
#include "helper.h"
using namespace std;

class ClsManager
{
public :
    vector<ClsStudent> StudentVector;
    vector<ClsCourse> CourseVector;
    vector <ClsStudentCourses> StudentCourse;

    int NextStudentId=0;
    int NextCourseId=0;

    void StartProgram()
    {
       
        
        int UserChoice=0;
        
        while (true) 
        {
            ClsMasseges::ShowMainMenu();
            cin>>UserChoice;

            switch (UserChoice)
        {
            case 1 : 
                Student(StudentVector);
                break;
            case 2 : 
                Courses(CourseVector);
                break;
            case 3 : 
                StudentCourses(StudentCourse);
                break;
            case 4 : 
                return;
            default:
                cout << "Invalid choice. Try again.\n";
                break;

        }

        }
        

    }

    void Student( vector<ClsStudent> &students)
    {
        while (true)
        {
            ClsMasseges::ShowStudentMenu();
            int UserChoice=0;
            cin>>UserChoice;
            ClsStudent student;
            switch (UserChoice)
            {
            case 1 :   
                student.DisplayStudents(students);
                break;
            case 2 :
                student.AddStudent(NextStudentId,students);
                break;
            case 3 :
                student.EditStudent(students);
                break;
            case 4 :
                student.DeleteStudent(students);
                break;
            case 5 : 
                return;
            default:
                cout << "Invalid choice. Try again.\n";
                break;
            }

        }
        

    }
    void Courses(vector<ClsCourse> &courses)
    {
        while (true)
        {
            ClsMasseges::ShowCourseMenu();
            int UserChoice=0;
            cin>>UserChoice;

            ClsCourse course;
            switch (UserChoice)
                {
                case 1 :   
                    course.DisplayCourses(courses);
                    break;
                case 2 :
                    course.AddCourse(NextCourseId,courses);
                    break;
                case 3 :
                    course.EditCourse(courses);
                    break;
                case 4 :
                    course.DeleteCourse(courses);
                    break;
                case 5 : 
                    return;
                default:
                    cout << "Invalid choice. Try again.\n";
                    break;
                }
        }
        
    }
    void StudentCourses(vector<ClsStudentCourses> &student_course_vector)
    {
        while (true)
        {
            ClsMasseges::ShowStudentCoursesMenu();
            int UserChoice=0;
            if (!(cin >> UserChoice))
            {
                cin.clear();                     // reset error state
                cin.ignore(1000, '\n');          // remove bad input
                cout << "Invalid input. Enter a number." << endl;
                continue;                        // go back to menu
            }
            ClsStudentCourses student_course;
            switch (UserChoice)
            {
                case 1 :   
                    {
                    string StudentName = helper::AskForStudentName();
                    if (student_course.DoesStudentExist(StudentName,StudentVector) == false) 
                    {
                        cout<<"student does not exists add the student first in the student Management menu"<<endl;
                        break;
                    }
                    string CourseName = helper::AskForCourseName();
                    if (student_course.DoesCourseExist(CourseName,CourseVector) == false)
                    {
                        cout<<"course does not exists add the course first in the course Management menu"<<endl;
                        break;
                    }   
                    if (student_course.Does_Student_Exist_In_Student_Course_Vector(StudentName,CourseName,student_course_vector)== true)
                    {
                        cout<<"that student allready exist in that course"<<endl;
                        break;
                    }
                    student_course.EnrollStudent(StudentName,CourseName,student_course_vector);
                    break;
                    }
                    
                case 2 :
                    {
                    string student_name = helper::AskForStudentName();
                    if (student_course.DoesStudentExist(student_name,StudentVector) == false) 
                    {
                        cout<<"student does not exists add the student first in the student Management menu"<<endl;
                        break;
                    }
                    student_course.ShowStudentCourses(student_name,student_course_vector);
                    break;  
                    }
                // ********
                
                case 3 :
                    {
                    string course_name = helper::AskForCourseName();
                    if (student_course.DoesCourseExist(course_name,CourseVector) == false)
                    {
                        cout<<"course does not exists add the course first in the course Management menu"<<endl;
                        break;
                    } 
                    student_course.ShowCourseStudents(course_name,student_course_vector);
                    break;
                    }
                    
                case 4 : 
                    {
                    string StudentName = helper::AskForStudentName();
                    if (student_course.DoesStudentExist(StudentName,StudentVector) == false) 
                    {
                        cout<<"student does not exists add the student first in the student Management menu"<<endl;
                        break;
                    }
                    string CourseName = helper::AskForCourseName();
                    if (student_course.DoesCourseExist(CourseName,CourseVector) == false)
                    {
                        cout<<"course does not exists add the course first in the course Management menu"<<endl;
                        break;
                    }   
                    student_course.ShowStudentGrade(StudentName,CourseName,student_course_vector);
                    break;
                    }
                    
                case 5 :
                {
                    string StudentName = helper::AskForStudentName();
                    if (student_course.DoesStudentExist(StudentName,StudentVector) == false) 
                    {
                        cout<<"student does not exists add the student first in the student Management menu"<<endl;
                        break;
                    }
                    string CourseName = helper::AskForCourseName();
                    if (student_course.DoesCourseExist(CourseName,CourseVector) == false)
                    {
                        cout<<"course does not exists add the course first in the course Management menu"<<endl;
                        break;
                    }
                    float grade = helper::AskForGrade();

                    student_course.ChangeStudentGrade(StudentName,CourseName,grade,student_course_vector);
                    break;
                }
                default:
                    cout << "Invalid choice. Try again.\n";
                    break;
                case 6 :
                    return;
                
            }
        }
        
    }

};