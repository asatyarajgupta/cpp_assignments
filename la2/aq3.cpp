#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a; 

    while (a--) {
     char str1[101], str2[101];
     cin >> str1 >> str2;  

     int len1 = 0;
     while (str1[len1] != '\0') len1++;

     int len2 = 0;
     while (str2[len2] != '\0') len2++;
     
     if (len1 != len2) {
      cout << "NO" << endl;
      continue;
     }

     int freq[256] = {0};

     for (int i = 0; i < len1; i++) {
      freq[(int)str1[i]]++;
      freq[(int)str2[i]]--;
     }

     bool isAnagram = true;
     for (int i = 0; i < 256; i++) {
      if (freq[i] != 0) {
       isAnagram = false;
       break;
      }
     }


     if (isAnagram) cout << "YES" << endl;
     else cout << "NO" << endl;
    }

    return 0;
}
