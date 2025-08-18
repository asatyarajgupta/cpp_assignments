#include<iostream>
using namespace std;

int main(){
    int arr[10],n;
    cout <<"enter the size of the array: ";
    cin>>n;

    cout << "enter the elements: \n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout<<"the reversed array is: ";
    for(int i=n-1; i>=0; i--){
        cout << arr[i] << " ";
    }

    return 0;
}
