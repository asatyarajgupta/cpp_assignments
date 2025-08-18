#include <iostream>
using namespace std;
int main() {
    char ch;
    cout<< "character?";
    cin>> ch;
    if(ch>= 'A' && ch <='Z') {
        ch += ch + ('a'- 'A'); 
    }
    cout << "Lowercase:" << ch << endl;
    return 0;
}
