#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n], ans[n];
    for(int i =0; i <n;i++) {
        cin >> arr[i];
    }
    int k =0;
    for (int i= 0; i< n;i++) {
        if(arr[i] == 0) {
             ans[k++] = 0;
        }
    for (int i =0; i< n;i++) {
         if (arr[i]== 1){
             ans[k++] = 1;
        } 
    }
    for(int i =0; i< n; i++) {
        if (arr[i] ==2) {
            ans[k++] = 2;
        }
    }
    for (int i = 0; i < n; i++) {
        cout<< ans[i]<<" ";
    }
    return 0;
}
}