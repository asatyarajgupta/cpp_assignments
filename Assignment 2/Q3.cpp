#include <iostream>

int findMissingNumber(const int arr[], int n) {
    int diff = (arr[n - 1] - arr[0]) / n; 

    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] - arr[i] != diff) {
            return arr[i] + diff; 
        }
    }

    return -1; 
}

int main() {
    int arr[] = {2, 4, 6, 10, 12}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    int missingNumber = findMissingNumber(arr, n);

    if (missingNumber != -1)
        std::cout << "The missing number is: " << missingNumber << std::endl;
    else
        std::cout << "No missing number found." << std::endl;

    return 0;
}