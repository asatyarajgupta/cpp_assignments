#include <iostream>
#include <vector>
using namespace std;

int countInversions(vector<int>& arr) {
    int count = 0;
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    vector<int> arr = {2, 3, 8, 6, 1};
    
    cout << "Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    
    int inversions = countInversions(arr);
    cout << "Number of inversions: " << inversions << endl;
    
    return 0;
}
