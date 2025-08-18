#include <iostream>
using namespace std;

void display(int mat[][3]) {
    int n = mat[0][2];
    cout << "Row Col Val\n";
    for (int i = 0; i <= n; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << "\n";
    }
}

void transpose(int mat[][3], int trans[][3]) {
    int row = mat[0][0], cols = mat[0][1], n = mat[0][2];
    trans[0][0] = cols;
    trans[0][1] = row;
    trans[0][2] = n;
    int k = 1;

    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= n; j++) {
            if (mat[j][1] == i) {
                trans[k][0] = mat[j][1];
                trans[k][1] = mat[j][0];
                trans[k][2] = mat[j][2];
                k++;
            }
        }
    }
}

void add(int a[][3], int b[][3], int sum[][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Matrices cannot be added\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2] + b[j][2];   // ✅ FIXED
            i++; j++; k++;
        }
        else if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            i++; k++;
        }
        else {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++; k++;
        }
    }
    while (i <= a[0][2]) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1;
}

void mult(int a[][3], int b[][3], int result[][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Matrices cannot be multiplied\n";
        return;
    }

    int bt[20][3];
    transpose(b, bt);

    result[0][0] = a[0][0];
    result[0][1] = b[0][1];
    int k = 1;

    for (int i = 1; i <= a[0][2]; ) {
        int row = a[i][0];
        for (int j = 1; j <= bt[0][2]; ) {
            int col = bt[j][0];
            int ii = i, jj = j, sum = 0;

            while (ii <= a[0][2] && a[ii][0] == row &&
                   jj <= bt[0][2] && bt[jj][0] == col) {
                if (a[ii][1] < bt[jj][1]) ii++;
                else if (a[ii][1] > bt[jj][1]) jj++;
                else {
                    sum += a[ii][2] * bt[jj][2];
                    ii++; jj++;
                }
            }

            if (sum != 0) {
                result[k][0] = row;
                result[k][1] = col;
                result[k][2] = sum;
                k++;
            }

            while (jj <= bt[0][2] && bt[jj][0] == col) jj++;
        }
        while (i <= a[0][2] && a[i][0] == row) i++;
    }
    result[0][2] = k - 1;
}

int main() {
    int A[5][3] = {
        {3,3,4}, {0,0,3}, {0,2,2}, {1,1,4}, {2,2,5}
    };
    int B[5][3] = {
        {3,3,4}, {0,0,2}, {0,2,1}, {1,1,3}, {2,2,2}
    };

    int T[10][3], S[10][3], M[20][3];

    cout << "MA\n"; display(A);
    cout << "\nMB\n"; display(B);

    cout << "\nTranspose A\n";
    transpose(A, T); display(T);

    cout << "\nA + B\n";
    add(A, B, S); display(S);

    cout << "\nA * B\n";
    mult(A, B, M); display(M);

    return 0;
}
