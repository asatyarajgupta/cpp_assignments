#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int t[200];
    for(int i= 0;i< 3*n-2 ; i++){ cin>>t[i];
    }
    int k1= 0,k2 =n-1,k3 =2*n-2;
    for(int i= 0;i <n; i++){
        for(int j =0; j<n; j++){
            if( i== j)  cout<<t[i]<<" ";
            else if( i==j+1) cout<< t[ k2+i]<< " ";
            else if(j ==i+1) cout<< t[k3+i ]<< " ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}
