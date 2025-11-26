#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;
    swap(arr[min_idx], arr[i]);
  }
  cout << "Selection Sort: ";
  printArray(arr, n);
}

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
  cout << "Insertion Sort: ";
  printArray(arr, n);
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
  cout << "Bubble Sort: ";
  printArray(arr, n);
}

void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

void mergeSortUtil(int arr[], int l, int r) {
  if (l >= r)
    return;
  int m = l + (r - l) / 2;
  mergeSortUtil(arr, l, m);
  mergeSortUtil(arr, m + 1, r);
  merge(arr, l, m, r);
}

void mergeSort(int arr[], int n) {
  mergeSortUtil(arr, 0, n - 1);
  cout << "Merge Sort: ";
  printArray(arr, n);
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quickSortUtil(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSortUtil(arr, low, pi - 1);
    quickSortUtil(arr, pi + 1, high);
  }
}

void quickSort(int arr[], int n) {
  quickSortUtil(arr, 0, n - 1);
  cout << "Quick Sort: ";
  printArray(arr, n);
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Original Array: ";
  printArray(arr, n);

  int temp[n];

  copy(arr, arr + n, temp);
  selectionSort(temp, n);
  copy(arr, arr + n, temp);
  insertionSort(temp, n);
  copy(arr, arr + n, temp);
  bubbleSort(temp, n);
  copy(arr, arr + n, temp);
  mergeSort(temp, n);
  copy(arr, arr + n, temp);
  quickSort(temp, n);

  return 0;
}
