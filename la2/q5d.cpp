#include<iostream>
using namespace std;
int main(){
    int n;
   cin>>n;
    int c[200];
    for (int i= 0;i <n*(n+1)/2; i++) {cin>>c[i];}
    int k=0;
    for(int i= 0;i< n;i++){
        for (int j= 0;j <n; j++){
            if(j >= i) {
                cout<<c[k++]<<" ";
            }
            else cout<<0<<" ";
        }
        cout<<endl;
    }
}
