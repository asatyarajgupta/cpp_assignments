#include <iostream>
#include <queue>
#include <string>
using namespace std;

void findFirstNonRepeating(string str) {
    queue<char> q;
    int count[26] = {0}; // Assuming only lowercase letters
    
    cout << "Processing string: " << str << endl;
    cout << "Output: ";
    
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        // Skip spaces
        if (ch == ' ') {
            cout << "-1 ";
            continue;
        }
        
        // Increment count for current character
        count[ch - 'a']++;
        
        // Add character to queue
        q.push(ch);
        
        // Remove characters from front of queue that are repeating
        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }
        
        // Print first non-repeating character or -1
        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    
    cout << "Enter a string (lowercase letters only): ";
    getline(cin, input);
    
    findFirstNonRepeating(input);
    
    return 0;
}
