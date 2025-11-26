#include <iostream>
using namespace std;

class DiagonalMatrix {
    int* arr;
    int n;
    
public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = 0;
        }
    }
    
    void set(int i, int j, int val) {
        if (i == j) {
            arr[i] = val;
        }
    }
    
    int get(int i, int j) {
        if (i == j) {
            return arr[i];
        }
        return 0;
    }
    
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

class LowerTriangular {
    int* arr;
    int n;
    
public:
    LowerTriangular(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2];
        for (int i = 0; i < n * (n + 1) / 2; i++) {
            arr[i] = 0;
        }
    }
    
    void set(int i, int j, int val) {
        if (i >= j) {
            int index = i * (i + 1) / 2 + j;
            arr[index] = val;
        }
    }
    
    int get(int i, int j) {
        if (i >= j) {
            int index = i * (i + 1) / 2 + j;
            return arr[index];
        }
        return 0;
    }
    
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    DiagonalMatrix dm(3);
    dm.set(0, 0, 1);
    dm.set(1, 1, 2);
    dm.set(2, 2, 3);
    
    cout << "Diagonal Matrix:" << endl;
    dm.display();
    cout << endl;
    
    LowerTriangular lt(3);
    lt.set(0, 0, 1);
    lt.set(1, 0, 2);
    lt.set(1, 1, 3);
    lt.set(2, 0, 4);
    lt.set(2, 1, 5);
    lt.set(2, 2, 6);
    
    cout << "Lower Triangular Matrix:" << endl;
    lt.display();
    
    return 0;
}
