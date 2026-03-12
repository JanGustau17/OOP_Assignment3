#pragma once

#include <vector>
#include <iostream>
#include <string>
using namespace std;

#include "Course.h"



class Student {
    private:
        string studentName;
        vector<Course> courses;
    
    public:
        Student(string name) {
            studentName = name;
        }
    
        void addCourse(Course c){
            courses.push_back(c);
        }
        
        
        double computeGPA(){
            double totalPts = 0;
            double totalCredits = 0;
            
            for (int i = 0; i < courses.size(); i++) {
                totalPts += courses[i].getTotalPts();
                totalCredits += courses[i].getCreditHours();
            }
            
            return totalPts/totalCredits;
        }
        
            
        string getStanding() {
            double gpa = computeGPA();
            
            if (gpa >= 3.70){
                return "Dean's List";
            } else if (gpa >= 2.00 && gpa < 3.70) {
                return "Good Standing";
            } else {
                return "Probation";
            }
        }
        
        string getName() const {
            return studentName;
        }
        vector<Course> getCourses(){
            return courses;
        }
        
};




