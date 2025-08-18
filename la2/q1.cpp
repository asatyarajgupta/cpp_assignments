#include<iostream>
using namespace std; 
int main (){
    int arr[] = {1,2,3,4,5,6};
    int s = 0;
    int e = size(arr) - 1;
    
    int target = 5;
    int result = -1;
 
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == target){
              result = mid;
              break;
        }
        if (arr[mid]<target){
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

if(result==-1){
   cout<<"element not found";
}
else{
    cout<<"element "<<target<<" found at index"<<result;
}

}