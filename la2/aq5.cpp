#include <vector>

void duplicateTwos(std::vector<int>& arr) {
    int n = arr.size();
    int countTwo = 0;


    for (int x : arr) {
        if (x == 2) countTwo++;
    }

    int i = n - 1;
    int j = n + countTwo - 1;


    while (i >= 0 && j >= 0) {
        if (arr[i] == 2) {
            if (j < n) arr[j] = 2;
            j--;
            if (j < n) arr[j] = 2;
            j--;
        } else {
            if (j < n) arr[j] = arr[i];
            j--;
        }
        i--;
    }
}
