/*
Name: Mukhammadali Yuldoshev
Date: 3/11/2026
Assignment 3 - Student Grade sHEET

Professor: Avijot Roy

(sorry, I had small amount of time left that I couldn't add my teammates' name)
*/



#include <iostream>
#include <iomanip>
#include <string>

#include "Course.h"
#include "Student.h"

using namespace std;

int askForNumber(string question, int smallest, int biggest) { //I have used AI for this problem, in order to solve if unrelated input used by users
    int answer;
    while (true) {
        cout << question;
        cin >> answer;
        if (!cin.fail() && answer >= smallest && answer <= biggest) {
            cin.ignore(100, '\n');
            return answer;
        }
        cout << "  Please type a number between " << smallest << " and " << biggest << ".\n";
        cin.clear();
        cin.ignore(100, '\n');
    }
}

string askForGrade(string question) {
    string answer;
    while (true) {
        cout << question;
        cin >> answer;
        cin.ignore(100, '\n');
        if (answer == "A"  || answer == "A-" ||
            answer == "B+" || answer == "B"  || answer == "B-" ||
            answer == "C+" || answer == "C"  || answer == "C-" ||
            answer == "D"  || answer == "F")
            return answer;
        cout << "  Sorry, Only these grades are allowed: A  A-  B+  B  B-  C+  C  C-  D  F\n";
    }
}

void printLine(int width, char ch = '-') {
    cout << string(width, ch) << '\n';
}

void printReport(Student& student) {
    vector<Course> courses = student.getCourses();

    const int W  = 60;
    const int NW = 28;
    const int CW =  9;
    const int GW =  9;
    const int TW = 10;

    double totalCredits = 0;
    double totalPoints  = 0;
    for (int i = 0; i < courses.size(); i++) {
        totalCredits += courses[i].getCreditHours();
        totalPoints  += courses[i].getTotalPts();
    }
    double gpa = student.computeGPA();

    cout << fixed << setprecision(2);

    printLine(W, '=');
    cout << setw((W + 20) / 2) << "Student Grade Report" << "\n";
    printLine(W, '=');
    cout << "Student:  " << student.getName() << "\n\n";

    cout << left  << setw(NW) << "Course"
         << right << setw(CW) << "Credits"
                  << setw(GW) << "GradePts"
                  << setw(TW) << "TotalPts"
         << "\n";
    printLine(W);

    for (int i = 0; i < courses.size(); i++) {
        cout << left  << setw(NW) << courses[i].getCourseName()
             << right << setw(CW) << courses[i].getCreditHours()
                      << setw(GW) << courses[i].getGradePts()
                      << setw(TW) << courses[i].getTotalPts()
             << "\n";
    }

    printLine(W);
    cout << left << setw(NW) << "Total Credits:"
         << right << setw(CW) << (int)totalCredits << "\n";
    cout << left << setw(NW) << "Total Points:"
         << right << setw(CW) << totalPoints << "\n";
    cout << left << setw(NW) << "Semester GPA:"
         << right << setw(CW) << gpa << "\n";
    cout << left << setw(NW) << "Standing:"
         << right << setw(CW) << student.getStanding() << "\n";
    printLine(W, '=');
}

int main() {
    string studentName;
    cout << "What is the student's full name? ";
    getline(cin, studentName);

    Student student(studentName);

    int numberOfCourses = askForNumber("How many courses? (1 to 6): ", 1, 6); //student can take max 6 courses for each semester (based on the internet) 

    for (int i = 1; i <= numberOfCourses; i++) {
        cout << "\n--- Course " << i << " ---\n";

        string courseName;
        cout << "  Course name: ";
        getline(cin, courseName);

        int credits = askForNumber("  How many credit hours? (0 to 6): ", 0, 6); // I have checked the website where max credits each class can have 6 credits. 
        string grade = askForGrade("  Letter grade (A  A-  B+  B  B-  C+  C  C-  D  F): ");

        student.addCourse(Course(courseName, credits, grade));
    }

    cout << "\n";
    printReport(student);

    return 0;
}







/*
rEFLECTION:

First tricky thing is timing, where I was running out of my time and not completing the project becuase of my teammates respomce
I totally get it, that also happened with me during hackathons, I have joined

Second thing is, building a table's allignemnt. I wanted to use for loop, but it took my time, so I choose different approach

Third, real time scenarios where requirements not fully told what specifically do. Example, what if students get F grade, and still get the credits. Which i had to think critically.


*/