#include<iostream>
using namespace std;

int main() {
    const int arr[] = {1,2,3,4,5,6,7};
    int count = 0;
    const int n = size(arr);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (int k = 2; abs(arr[i] - arr[j]) == k) {
                count++;
            }
        }
    }

    cout << count;
}
