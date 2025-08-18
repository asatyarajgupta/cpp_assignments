#include<iostream>
using namespace std;
int main() {
    int arr[10] = {4,4,5,5,5,5,5,6,6,7};
    const int n =10;
       int j= 0;
        for(int i=0; i < n - 1; i++) {
        if (arr[i] != arr[i+1]){
            arr[j] = arr[i];
            j++;
        }
    }
    arr[j]= arr[n -1];
    j++;
        for(int i = 0;i <j;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

            
            
                      
                      
