#include <iostream>
using namespace std;

class Marks {

    int departments;
    int* students;
    int** marks;

    // helper to allocate
    void allocator(int r) {
        marks = new int*[r];
        students = new int[departments];
        for (int i = 0; i < r; i++) {
            cout << "Enter students in Department " << i+1 << ": ";
            cin >> students[i];
            marks[i] = new int[students[i]];
            for (int j = 0; j < students[i]; j++) {
                marks[i][j] = -1;
            }
        }
    }

    // helper to free memory
    void freeArray() {
        for (int i=0; i<departments; i++){
            delete[] marks[i];
        }
        delete[] marks;
    }

    // helper to input data
    void inputData() {
        cout << endl << "Please enter the marks for each department:" << endl << endl;
        for (int i=0; i<departments; i++) {
            cout << endl << "Department " << i+1 << ": " << endl;
            for (int j=0; j<students[i]; j++) {
                cout << "Marks of Student " << j+1 << ": ";
                cin >> marks[i][j];
            }
            cout << endl;
        }
    }

    public:

    // constructor
    Marks(int dept) {
        departments = dept;
        allocator(departments);
        inputData();
    }

    // destructor
    ~Marks() {
        freeArray();
    }


    // print
    void print() {
        for (int i=0; i<departments; i++) {
            for (int j=0; j<students[i]; j++) {
                cout << marks[i][j] << "  ";
            }
            cout << endl;
        }
    }

    // output total
    void total() {
        int sum = 0;
        for (int i=0; i<departments; i++){
            cout << "Department " << i+1 << " Total: ";
            for (int j=0; j<students[i]; j++) {
                sum += marks[i][j];
            }
            cout << sum << endl;
            sum = 0;
        }
    }
    
    // output average
    void average() {
        int sum = 0;
        for (int i=0; i<departments; i++){
            cout << "Department " << i+1 << " Average: ";
            for (int j=0; j<students[i]; j++) {
                sum += marks[i][j];
            }
            cout << sum/students[i] << endl;
            sum = 0;
        }
    }

    // output highest
    // could just use the total fn to return int* totalArr
    // but it would also output total couts again
    void highest() {
        int sum = 0;
        int* totalArr = new int[departments];
        for (int i=0; i<departments; i++){
            for (int j=0; j<students[i]; j++) {
                sum += marks[i][j];
            }
            totalArr[i] = sum;
            sum = 0;
        }
        int max = 0;
        int current = -1;
        for (int i=0; i<departments; i++) {
            if (totalArr[i] > max) {
                max = totalArr[i];
                current = i;
            }
        }
        cout << "The department with highest marks is Department " << current + 1 << " with " << max << " marks!" << endl;
    }

    // output lowest
    void lowest() {
        int sum = 0;
        int* totalArr = new int[departments];
        for (int i=0; i<departments; i++){
            for (int j=0; j<students[i]; j++) {
                sum += marks[i][j];
            }
            totalArr[i] = sum;
            sum = 0;
        }
        int min = 1000;
        int mincurrent = -1;
        for (int i=0; i<departments; i++) {
            if (totalArr[i] < min) {
                min = totalArr[i];
                mincurrent = i;
            }
        }
        cout << "The department with lowest marks is Department " << mincurrent + 1 << " with " << min << " marks" << endl;
    }
};


int main() {
    Marks markStudent(3);

    markStudent.print();
    cout << endl;
    markStudent.total();
    cout << endl;
    markStudent.average();
    cout << endl;
    markStudent.highest();
    cout << endl;
    markStudent.lowest();
    cout << endl;

}