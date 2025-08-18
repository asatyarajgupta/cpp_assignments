#include<iostream>

using namespace std;

int main(){

 int arr[] = {1,2,4,5,6};

 int n = size(arr);

 int tsum = n*(n+1)/2;

 int sum = 0;

 for(int i = 0; i < n;i++){

     sum += arr[i];

 }
  
 int missing = tsum - sum;

 cout<<missing;
}