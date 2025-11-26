#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    
    cout << "Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    
    // Sum of each row
    cout << "Sum of each row:" << endl;
    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 4; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Row " << (i + 1) << ": " << rowSum << endl;
    }
    cout << endl;
    
    // Sum of each column
    cout << "Sum of each column:" << endl;
    for (int j = 0; j < 4; j++) {
        int colSum = 0;
        for (int i = 0; i < 3; i++) {
            colSum += matrix[i][j];
        }
        cout << "Column " << (j + 1) << ": " << colSum << endl;
    }
    
    return 0;
}
