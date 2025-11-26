#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string concatenate(string str1, string str2) {
    return str1 + str2;
}

string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}

string removeVowels(string str) {
    string result = "";
    for (char c : str) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }
    return result;
}

void sortStrings(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int main() {
    string str1 = "Hello ";
    string str2 = "World!";
    cout << "Concatenation: " << concatenate(str1, str2) << endl;
    
    string original = "Programming";
    cout << "Reverse: " << reverseString(original) << endl;
    
    string withVowels = "Hello World";
    cout << "Remove vowels: " << removeVowels(withVowels) << endl;
    
    string strings[] = {"zebra", "apple", "banana", "cherry"};
    int n = 4;
    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << strings[i] << " ";
    }
    cout << endl;
    
    sortStrings(strings, n);
    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << strings[i] << " ";
    }
    cout << endl;
    
    char upperChar = 'A';
    cout << "Lowercase: " << toLower(upperChar) << endl;
    
    return 0;
}
