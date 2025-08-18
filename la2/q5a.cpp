#include <iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    int a[50];
    for(int i =0;i <n;i++)
        cin>> a[i];

    for (int i= 0;i<n ;i++){
        for(int j= 0; j <n; j++){
            if(i ==j) cout<<a[i] <<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}
