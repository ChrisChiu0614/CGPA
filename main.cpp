#include <iostream>
#include <string>
using namespace std;

// declared method
void classificateGrade(float &percent);
bool getMarkValue(int &totalMarks, int &obtainMarks);
void showMenu();

// const attribute
const int START = 1;
const int END = 2;

int main()
{
    int totalMarks, obtainMarks;
    float percent = 0.0, gpa;

    while (true)
    {
        showMenu();
        int option;
        cin >> option;
        switch (option)
        {
        case START:
            if (getMarkValue(totalMarks, obtainMarks))
            {
                cout << "======================================" << endl;
                percent = 100 * float(obtainMarks) / float(totalMarks);
                classificateGrade(percent);
                cout << "======================================" << endl;
            }
            break;
        case END:
            cout << "BYE BYE!" << endl;
            return 1;
        default:
            break;
        }
    }
}

/**
 * to display menu
 * */ 
void showMenu(){
    cout << "===== WELCOME TO CGPA CALCULATOR =====" << endl;
    cout << "=====           By : Chris       =====" << endl;
    cout << "=====           1. START         =====" << endl;
    cout << "=====           2. EXIT          =====" << endl;
    cout << "Enter the option : " << endl;
}

/**
 * to set the totalMarks and obtainMarks's value logic
*/
bool getMarkValue(int &totalMarks, int &obtainMarks)
{

    cout << "Enter the totalMarks: " << endl;
    cin >> totalMarks;
    if (totalMarks < 0)
    {
        cout << "Total marks should be a positive number." << endl;
        return false;
    }
    cout << "Enter the obtainMarks: " << endl;
    cin >> obtainMarks;
    if (obtainMarks < 0 || obtainMarks > totalMarks)
    {
        cout << "Obtained marks should be between 0 and " << totalMarks << "." << endl;
        return false;
    }

    return true;
}

/**
 * to calculate percent for classification your gpa and grade
*/
void classificateGrade(float &percent)
{
    float gpa = 0.0;
    string grade = "";
    if (percent >= 90 && percent <= 100)
    {
        gpa = 4.00;
        grade = "A+";
    }
    else if (percent >= 85 && percent <= 89.99)
    {
        gpa = 4.00;
        grade = "A";
    }
    else if (percent >= 80 && percent <= 84.99)
    {
        gpa = (percent * 3.66) / 80;
        grade = "A-";
    }
    else if (percent >= 75 && percent <= 79.99)
    {
        gpa = (percent * 3.33) / 75;
        grade = "B+";
    }
    else if (percent >= 71 && percent <= 74.99)
    {
        gpa = (percent * 3.00) / 71;
        grade = "B";
    }
    else if (percent >= 68 && percent <= 70.99)
    {
        gpa = (percent * 2.66) / 68;
        grade = "B-";
    }
    else if (percent >= 61 && percent <= 67.99)
    {
        gpa = (percent * 2.00) / 61;
        grade = "C";
    }
    else if (percent >= 50 && percent <= 60.99)
    {
        gpa = (percent * 1.00) / 50;
        grade = "D";
    }
    else if (percent < 50)
    {
        gpa = 0.00;
        grade = "F";
    }
    cout.precision(3);
    cout << "Your GPA is: " << gpa << endl;
    cout << "Your grade is: " << grade << endl;
    cout << "Your percentage is: " << percent << "%" << endl;
}