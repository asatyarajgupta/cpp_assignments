#include<iostream>
using namespace std;
int main() {
    int n;
    cout <<"Enter size of symmetric matrix";
    cin >>n;
    int sym[1000];
    cout <<"Enter elements of lower triangle";
    for (int i= 0;i< n*(n+1)/2; i++)
        cin>> sym[i];
    for (int i =0,k =0; i< n;i++) {
        for (int j = 0;j <n; j++) {
            if (i >=j) { 
                cout<< sym[k++]<< " ";
            } else {
                cout<< sym[j*(j+1)/2 +i]<< " ";
            }
        }
        cout << endl;
    }
}
