#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    char arr[100][100], temp[100];

    cout << "Enter number of strings: ";
    cin >> n;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    for(int i =0;i < n-1; i++) {
        for(int j =i+1; j< n; j++) {\

            if(strcmp(arr[i],arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    cout << "Strings";
    for(int i =0;i < n;i++)
        cout<< arr[i]<<endl;

    return 0;
}

