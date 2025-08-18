#include<iostream>
using namespace std;
int main(){

    int arr[] = {1,2,3,4,5,7};

    int n = size(arr);

    int s = 0; 
    int e = n - 1;
     int missing = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
             if(arr[mid] != mid+1 && arr[mid - 1] == mid){
                missing  = mid + 1;
               break;
             }
             else {
             if(arr[mid] == mid+1){
                       s = mid + 1;
             }
             else{
                e = mid - 1;

             }
            }
    } 

    cout<<missing << endl ;
    return 0 ;
}

