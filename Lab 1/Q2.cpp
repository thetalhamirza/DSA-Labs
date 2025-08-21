#include <iostream>
#include <cstring>
using namespace std;

class Exam {
    private:
    char* studentName;
    char* examDate;
    float score;

    public:       

    // Parametric Constructor

    Exam(const char* sn, const char* ed, const float s) {       
        studentName = new char[strlen(sn) + 1];
        strcpy(studentName, sn);

        examDate = new char[strlen(ed) + 1];
        strcpy(examDate, ed);
        score = s;
    }

    // Setters

    void setStudentName(const char* n) {
        delete[] studentName;
        studentName = new char[strlen(n) + 1];
        strcpy(studentName, n);
    }

    void setExamDate(const char* ed) {
        delete[] examDate;
        examDate = new char[strlen(ed) + 1];
        strcpy(examDate, ed);
    }

    void setScore(float s) {score = s;}

    // Display

    void showDetails() const {
        cout << "Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }

    // Destructor

    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }

    // Omitted copy constructor and copy assignment operator
    // Will generate shallow copy

};

int main() {

    // Original object
    Exam exam1("Talha", "10 October", 95.0);
    cout << "Original Exam Record: " << endl;
    exam1.showDetails();

    cout << endl;
    
    // Shallow copying
    Exam exam2 = exam1;
    cout << "Copied Exam Record: " << endl;
    exam2.showDetails();
    
    cout << endl;
    
    // Modifying exam2
    exam2.setStudentName("Sheikh Abdul Qadir");
    exam2.setExamDate("10 June");
    exam2.setScore(65.0);
    
    cout << endl;
    
    // couting details for both objects
    cout << "Exam 1 details: " << endl;
    exam1.showDetails();
    
    cout << endl;
    
    cout << "Exam 2 details: " << endl;
    exam2.showDetails();

    // throws error at the end because both objects try to delete[] at the same memory address
}
