#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    cout << "Hi! I'll help you convert math expressions!" << endl;
    cout << "Give me a normal math expression (like a+b*c): ";
    
    string expression;
    getline(cin, expression);
    
    stack<char> operatorBox;
    string result = "";
    
    cout << "\nAlright! Let me convert: " << expression << endl;
    cout << "I'll show you each step..." << endl << endl;
    
    for (int i = 0; i < expression.length(); i++) {
        char current = expression[i];
        
        // Skip spaces - nobody likes them anyway!
        if (current == ' ') continue;
        
        cout << "Looking at: '" << current << "' -> ";
        
        // If it's a letter or number, just add it to result
        if ((current >= 'a' && current <= 'z') || (current >= '0' && current <= '9')) {
            result += current;
            cout << "It's a number/letter! Adding to result: " << result << endl;
        }
        // If it's an opening bracket, save it for later
        else if (current == '(') {
            operatorBox.push(current);
            cout << "Opening bracket! I'll remember this." << endl;
        }
        // If it's a closing bracket, time to empty the box!
        else if (current == ')') {
            cout << "Closing bracket! Let me get everything until the opening..." << endl;
            while (!operatorBox.empty() && operatorBox.top() != '(') {
                result += operatorBox.top();
                cout << "  Adding " << operatorBox.top() << " to result: " << result << endl;
                operatorBox.pop();
            }
            if (!operatorBox.empty()) operatorBox.pop(); // Remove the '('
        }
        // If it's a math operator
        else if (current == '+' || current == '-' || current == '*' || current == '/' || current == '^') {
            // Figure out how important this operator is
            int myImportance = 1; // + and - are least important
            if (current == '*' || current == '/') myImportance = 2;
            if (current == '^') myImportance = 3; // ^ is most important
            
            cout << "It's an operator! Importance level: " << myImportance << endl;
            
            // Take out more important operators first
            while (!operatorBox.empty() && operatorBox.top() != '(') {
                char topOp = operatorBox.top();
                int topImportance = 1;
                if (topOp == '*' || topOp == '/') topImportance = 2;
                if (topOp == '^') topImportance = 3;
                
                if (topImportance >= myImportance) {
                    result += topOp;
                    cout << "  " << topOp << " is more important, adding to result: " << result << endl;
                    operatorBox.pop();
                } else {
                    break;
                }
            }
            
            operatorBox.push(current);
            cout << "  Saved " << current << " for later!" << endl;
        }
        
        cout << endl;
    }
    
    // Don't forget the operators we saved!
    cout << "Finished reading! Now adding leftover operators..." << endl;
    while (!operatorBox.empty()) {
        result += operatorBox.top();
        cout << "Adding " << operatorBox.top() << " to result: " << result << endl;
        operatorBox.pop();
    }
    
    cout << "\n🎉 DONE!" << endl;
    cout << "Your expression: " << expression << endl;
    cout << "Converted to: " << result << endl;
    cout << "\nNow computers can easily calculate this!" << endl;
    
    return 0;
}
