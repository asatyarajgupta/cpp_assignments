#include <iostream>
#include <algorithm>

void removeDuplicates(int arr[], int &size) {
    std::sort(arr, arr + size);

    int uniqueIndex = 0; 
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[uniqueIndex++] = arr[i];
        }
    }
    arr[uniqueIndex++] = arr[size - 1];

    
    size = uniqueIndex;
}

int main() {
    int arr[6] = {4, 2, 2, 4, 3, 3};
    int size = 6;

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    removeDuplicates(arr, size);

    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}