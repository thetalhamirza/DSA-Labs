#include <iostream>
using namespace std;

class Matrix {

    int rows, columns, initial;
    int** arr;

    // helper fn to allocate 2d matrix
    void createMatrix(const int row, const int col, const int initVal = 0) {
        arr = new int*[row];
        for (int i=0; i<row; i++) {
            arr[i] = new int[col];
            for (int j=0; j<col; j++) {
                arr[i][j] = initVal;
            }
        }
    }

    // helper to free matrix
    void deleteMatrix() {
        for (int i=0; i<rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }

    public:
        // Constructor
        Matrix(int r, int c, int iv=0) {
            rows = r;
            columns = c;
            initial = iv;
            createMatrix(r, c, iv);
        }

        // Destructor
        ~Matrix() {
            deleteMatrix();
        }

        // Resizer
        void resizeMatrix(int newRow, int newCol, int initVal=0) {
            int** newArr;
            newArr = new int*[newRow];
            for (int i=0; i<newRow; i++) {
                newArr[i] = new int[newCol];
                for (int j=0; j<newCol; j++) {
                    if (i<rows && j<columns) {
                        newArr[i][j] = arr[i][j];
                    }   else {
                        newArr[i][j] = initVal;
                    }
                }
            }
            deleteMatrix();
            arr = newArr;
            rows = newRow;
            columns = newCol;
        } 

        // transpose (rotating matrix)
        void transpose() {
            int** newArr;
            newArr = new int*[columns];
            for (int i=0; i<columns; i++) {
                newArr[i] = new int[rows];
                for (int j=0; j<rows; j++) {
                    newArr[i][j] = arr[j][i];
                }
            }
            deleteMatrix();
            arr = newArr;
            int temp = rows;
            rows = columns;
            columns = temp;
        }

        // Couting matrix data
        void printMatrix() {
            for (int i=0; i<rows; i++) {
                for (int j=0; j<columns; j++) {
                    int val = arr[i][j];
                    if ((i+j) % 2 == 1) {
                        val += 2;
                    }
                    cout << val << " ";
                }
                cout << endl;
            }
        }



};

int main() {
    Matrix matrix(5, 7, 1);
    matrix.printMatrix();

    cout << endl;
    // Testing Resize
    matrix.resizeMatrix(2,3);
    matrix.printMatrix();
    
    cout << endl;
    // Testing Transpose
    matrix.transpose();
    matrix.printMatrix();

    return 0;
}