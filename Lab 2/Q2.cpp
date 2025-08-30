#include <iostream>
using namespace std;

class Marks {

    int students, subjects;
    int** marks;

    // helper to allocate
    void allocator(int r, int c) {
        marks = new int*[r];
        for (int i = 0; i < r; i++) {
            marks[i] = new int[c];
            for (int j = 0; j < c; j++) {
                marks[i][j] = -1;
            }
        }
    }

    // helper to free memory
    void freeArray() {
        for (int i=0; i<students; i++){
            delete[] marks[i];
        }
        delete[] marks;
    }

    // helper to input data
    void inputData() {
        cout << endl << "Please enter the data for each student:" << endl << endl;
        for (int i=0; i<students; i++) {
            cout << endl << "Student " << i+1 << ": " << endl;
            for (int j=0; j<subjects; j++) {
                cout << "Subject " << j+1 << ": ";
                cin >> marks[i][j];
            }
            cout << endl;
        }
    }

    public:

    // constructor
    Marks(int student, int subject) {
        students = student;
        subjects = subject;
        allocator(student, subject);
        inputData();
    }

    // destructor
    ~Marks() {
        freeArray();
    }


    // print
    void print() {
        for (int i=0; i<students; i++) {
            for (int j=0; j<subjects; j++) {
                cout << marks[i][j] << "  ";
            }
            cout << endl;
        }
    }

    // output total
    void total() {
        int sum = 0;
        for (int i=0; i<students; i++){
            cout << "Student " << i+1 << " Total: ";
            for (int j=0; j<subjects; j++) {
                sum += marks[i][j];
            }
            cout << sum << endl;
            sum = 0;
        }
    }
    
    // output average
    void average() {
        int sum = 0;
        for (int i=0; i<students; i++){
            cout << "Student " << i+1 << " Average: ";
            for (int j=0; j<subjects; j++) {
                sum += marks[i][j];
            }
            cout << sum/subjects << endl;
            sum = 0;
        }
    }

    // output topper
    // could just use the total fn to return int* totalArr
    // but it was also outputting total statements again
    void topper() {
        int sum = 0;
        int* totalArr = new int[students];
        for (int i=0; i<students; i++){
            for (int j=0; j<subjects; j++) {
                sum += marks[i][j];
            }
            totalArr[i] = sum;
            sum = 0;
        }
        int max = 0;
        int current = -1;
        for (int i=0; i<students; i++) {
            if (totalArr[i] > max) {
                max = totalArr[i];
                current = i;
            }
        }
        cout << "The topper is Student " << current + 1 << " with " << max << " marks!" << endl;
    }
};


int main() {
    Marks markStudent(5, 4);

    markStudent.print();
    cout << endl;
    markStudent.total();
    cout << endl;
    markStudent.average();
    cout << endl;
    markStudent.topper();
    cout << endl;

}