#include<iostream>
using namespace std;

int main() {
    int a[10][10], b[10][10], res[10][10];
    int c, d, e, f;
    cout << "number of rows for matrix 1: ";
    cin >> c;
    cout << "number of columns for matrix 1: ";
    cin >> d;
    cout << "number of rows for matrix 2: ";
    cin >> e;
    cout << "number of columns for matrix 2: ";
    cin >> f;
    if (d != e) {
        cout << "not possible!" << endl;
        return 0;
    }
    cout << "Enter elements of 1st matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Enter elements of 2nd matrix:\n";
    for (int i = 0; i < e; i++) {
        for (int j = 0; j < f; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < f; j++) {
            res[i][j] = 0;
            for (int k = 0; k < d; k++) { // or k < e
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "\nResultant Matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < f; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;   }
