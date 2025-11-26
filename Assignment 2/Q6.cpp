#include <iostream>
using namespace std;

struct Triplet {
    int row, col, val;
};

class SparseMatrix {
    Triplet* data;
    int rows, cols, count;
    
public:
    SparseMatrix(int r, int c) {
        rows = r;
        cols = c;
        count = 0;
        data = new Triplet[100];
    }
    
    void insert(int r, int c, int v) {
        if (v != 0) {
            data[count].row = r;
            data[count].col = c;
            data[count].val = v;
            count++;
        }
    }
    
    void display() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int val = 0;
                for (int k = 0; k < count; k++) {
                    if (data[k].row == i && data[k].col == j) {
                        val = data[k].val;
                        break;
                    }
                }
                cout << val << " ";
            }
            cout << endl;
        }
    }
    
    SparseMatrix transpose() {
        SparseMatrix result(cols, rows);
        for (int i = 0; i < count; i++) {
            result.insert(data[i].col, data[i].row, data[i].val);
        }
        return result;
    }
    
    SparseMatrix add(SparseMatrix& other) {
        SparseMatrix result(rows, cols);
        
        for (int i = 0; i < count; i++) {
            result.insert(data[i].row, data[i].col, data[i].val);
        }
        
        for (int i = 0; i < other.count; i++) {
            bool found = false;
            for (int j = 0; j < result.count; j++) {
                if (result.data[j].row == other.data[i].row && 
                    result.data[j].col == other.data[i].col) {
                    result.data[j].val += other.data[i].val;
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.insert(other.data[i].row, other.data[i].col, other.data[i].val);
            }
        }
        
        return result;
    }
};

int main() {
    SparseMatrix m1(3, 3);
    m1.insert(0, 0, 1);
    m1.insert(0, 2, 3);
    m1.insert(1, 1, 2);
    
    cout << "Matrix 1:" << endl;
    m1.display();
    
    SparseMatrix m2(3, 3);
    m2.insert(0, 0, 2);
    m2.insert(1, 1, 4);
    m2.insert(2, 2, 5);
    
    cout << "\nMatrix 2:" << endl;
    m2.display();
    
    cout << "\nTranspose of Matrix 1:" << endl;
    SparseMatrix t1 = m1.transpose();
    t1.display();
    
    cout << "\nAddition:" << endl;
    SparseMatrix sum = m1.add(m2);
    sum.display();
    
    return 0;
}
