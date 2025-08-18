#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char str[100];
    char result[100];
    
    cout <<"Enter";
    gets(str); 
    int j = 0;
    for(int i= 0; i<strlen(str);i++) {
        char ch = str[i];
        if(ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch != 'u'&& ch !='A' && ch !='E' && ch!='I' && ch!='O' && ch!= 'U') {
     result[j] =ch;
            j++;
        }
    }
 result[j] = '\0';

    cout<<result;

    return 0;
}
