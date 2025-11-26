#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    cout << "Hey! Let's check if your brackets are balanced!" << endl;
    cout << "Type any expression (like math formulas): ";
    
    string expression;
    getline(cin, expression);
    
    stack<char> bracketStack;
    
    cout << "\nOkay, let me check: " << expression << endl;
    cout << "Here's what I'm doing..." << endl;
    
    for (int i = 0; i < expression.length(); i++) {
        char current = expression[i];
        
        // When I see an opening bracket
        if (current == '(' || current == '[' || current == '{') {
            bracketStack.push(current);
            cout << "I found '" << current << "' - I'll remember this one!" << endl;
        }
        // When I see a closing bracket  
        else if (current == ')' || current == ']' || current == '}') {
            cout << "I found '" << current << "' - let me check if it matches...";
            
            // Oops, no opening bracket to match with
            if (bracketStack.empty()) {
                cout << " Nope! There's no opening bracket for this!" << endl;
                cout << "\nSorry, your brackets are NOT balanced 😞" << endl;
                return 0;
            }
            
            // Get the last opening bracket I remembered
            char lastOpening = bracketStack.top();
            bracketStack.pop();
            
            // Check if they're a matching pair
            if ((lastOpening == '(' && current == ')') ||
                (lastOpening == '[' && current == ']') ||
                (lastOpening == '{' && current == '}')) {
                cout << " Yes! It matches with '" << lastOpening << "' 👍" << endl;
            } else {
                cout << " Nope! '" << current << "' doesn't match with '" << lastOpening << "'" << endl;
                cout << "\nSorry, your brackets are NOT balanced 😞" << endl;
                return 0;
            }
        }
    }
    
    // Check if I still remember any unmatched opening brackets
    if (!bracketStack.empty()) {
        cout << "Hmm, I still have some unmatched opening brackets left over..." << endl;
        cout << "\nSorry, your brackets are NOT balanced 😞" << endl;
    } else {
        cout << "\nAwesome! Your brackets are perfectly BALANCED! 🎉" << endl;
        cout << "Every opening bracket has its closing partner!" << endl;
    }
    
    return 0;
}
