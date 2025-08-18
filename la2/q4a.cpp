#include<iostream>
#include<cstring>

using namespace std; 
 
int main(){
    char str1[100], str2[100], str3[100] ;

    gets(str1);
    gets(str2);
    gets(str3);

    int i = 0;
    int j = 0;
    int k = 0;
    
    while(str1[i] != '\0'){
        str3[k] = str1[i];
        k++;
        i++;
    }
      while(str2[j] != '\0'){
        str3[k] = str2[j];
        k++;
        j++;
    }

    puts(str3);
}

