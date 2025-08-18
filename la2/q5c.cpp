#include <iostream>
using namespace std;
int main(){
    int n; 
    cin>>n;
    int b[200];
    for(int i= 0;i <n*(n+1)/2; i++) {
        cin>>b[i];
    }
    int k=0;
    for(int i =0; i< n; i++){
        for(int j= 0; j<n;j++){
            if (j<=i){
                cout<<b[k++]<<" ";
            } 
            else cout<<"0";
        }
        cout<<endl;
    }
}
