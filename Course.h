#pragma once  //this is new (which not inlcuded on the class we have learned). 
//I used 'pragma once' because it avoids multiple class with single names


#include <string>
using namespace std;


class Course{
  private:
    string courseName;
    int creditHours;
    string letterGrade;
    
    
    double GradePts;
    double TotalPts;

  public:
    Course(string name, int credits, string grade){
        courseName = name;
        creditHours = credits;
        letterGrade = grade;
        
        if (grade == "A"){ //switch method used (i don't know what else it's called)
            GradePts = 4.0;
        } else if ( grade == "A-"){
            GradePts = 3.7;
        } else if (grade == "B+"){
            GradePts = 3.3;
        } else if ( grade == "B"){
            GradePts = 3.0;
        } else if(grade == "B-"){
            GradePts = 2.7;
        } else if ( grade == "C+"){
            GradePts = 2.3;
        } else if (grade == "C"){
            GradePts = 2.0;
        } else if ( grade == "C-"){
            GradePts = 1.7;
        } else if(grade == "D"){
            GradePts = 1.0;
        } else if ( grade == "F"){
            GradePts = 0.0;
            credits = 0; //if student fails the class, their credits won't be counted as earned credits. Therefore, student gets no credit. 
        } else {
            GradePts = 0.0; //could be returned as an message but I didn't do it
        };
        
        TotalPts = creditHours * GradePts;
        
    };
    
    string getCourseName() const {return courseName;};
    int getCreditHours() const {return creditHours;};
    string getLetterGrade() const {return letterGrade;};
    double getGradePts() const {return GradePts;};
    double getTotalPts() const {return TotalPts;};

    
};