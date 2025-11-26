#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countDistinct(vector<int> arr) {
    unordered_set<int> unique;
    
    for (int x : arr) {
        unique.insert(x);
    }
    
    return unique.size();
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 2, 3, 1};
    
    cout << "Array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    
    int distinctCount = countDistinct(arr);
    cout << "Number of distinct elements: " << distinctCount << endl;
    
    return 0;
}
