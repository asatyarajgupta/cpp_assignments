#include<iostream>
using namespace std;
int main(){
    int n;
    cin >>n;
    int a[100];
    for(int i= 0;i< n;i++) {
        cin>> a[i];
    }
    int inv = 0;
    for(int i =0;i < n; i++){
        for (int j= i+1;j <n; j++){
            if (a[i] > a[j]) {
            inv++;
            }
        }
    }
    cout<< "Number of inversions is"<<inv << endl;
}
