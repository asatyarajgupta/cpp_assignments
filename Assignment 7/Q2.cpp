#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void improvedSelectionSort(int arr[], int n) {
  for (int i = 0; i < n / 2; i++) {
    int min_idx = i;
    int max_idx = i;

    for (int j = i + 1; j < n - i; j++) {
      if (arr[j] < arr[min_idx])
        min_idx = j;
      if (arr[j] > arr[max_idx])
        max_idx = j;
    }

    if (max_idx == i && min_idx == n - i - 1) {
      swap(arr[min_idx], arr[max_idx]);
    } else if (max_idx == i) {
      swap(arr[max_idx], arr[n - i - 1]);
      swap(arr[min_idx], arr[i]);
    } else {
      swap(arr[min_idx], arr[i]);
      swap(arr[max_idx], arr[n - i - 1]);
    }
  }
}

int main() {
  int arr[] = {23, 78, 45, 8, 32, 56};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original Array: ";
  printArray(arr, n);

  improvedSelectionSort(arr, n);

  cout << "Sorted Array: ";
  printArray(arr, n);

  return 0;
}
