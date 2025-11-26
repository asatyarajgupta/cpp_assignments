#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    cout << "Hey! I'm your math calculator!" << endl;
    cout << "Give me a postfix expression (like 23+): ";
    
    string expression;
    getline(cin, expression);
    
    stack<int> numberPile;
    
    cout << "\nAlright! Let me solve: " << expression << endl;
    cout << "Watch me work through this step by step..." << endl << endl;
    
    for (int i = 0; i < expression.length(); i++) {
        char current = expression[i];
        
        // Skip spaces
        if (current == ' ') continue;
        
        cout << "I see: '" << current << "' -> ";
        
        // If it's a number, save it!
        if (current >= '0' && current <= '9') {
            int number = current - '0'; // Convert character to actual number
            numberPile.push(number);
            cout << "It's the number " << number << "! Saving it for later." << endl;
        }
        // If it's a math symbol, time to calculate!
        else if (current == '+' || current == '-' || current == '*' || current == '/' || current == '^') {
            cout << "It's math time! I need 2 numbers..." << endl;
            
            // Make sure I have enough numbers
            if (numberPile.size() < 2) {
                cout << "Oops! I don't have enough numbers to work with!" << endl;
                return 1;
            }
            
            // Get the two most recent numbers
            int secondNumber = numberPile.top(); numberPile.pop();
            int firstNumber = numberPile.top(); numberPile.pop();
            
            int answer;
            
            cout << "  Taking " << firstNumber << " and " << secondNumber << endl;
            
            if (current == '+') {
                answer = firstNumber + secondNumber;
                cout << "  " << firstNumber << " + " << secondNumber << " = " << answer << endl;
            }
            else if (current == '-') {
                answer = firstNumber - secondNumber;
                cout << "  " << firstNumber << " - " << secondNumber << " = " << answer << endl;
            }
            else if (current == '*') {
                answer = firstNumber * secondNumber;
                cout << "  " << firstNumber << " × " << secondNumber << " = " << answer << endl;
            }
            else if (current == '/') {
                if (secondNumber == 0) {
                    cout << "  Wait! I can't divide by zero! That's impossible!" << endl;
                    return 1;
                }
                answer = firstNumber / secondNumber;
                cout << "  " << firstNumber << " ÷ " << secondNumber << " = " << answer << endl;
            }
            else if (current == '^') {
                answer = 1;
                for (int j = 0; j < secondNumber; j++) {
                    answer *= firstNumber;
                }
                cout << "  " << firstNumber << " to the power of " << secondNumber << " = " << answer << endl;
            }
            
            numberPile.push(answer);
            cout << "  Saving the answer: " << answer << endl;
        }
        
        // Show what numbers I'm currently holding
        cout << "  My numbers now: ";
        if (numberPile.empty()) {
            cout << "none";
        } else {
            stack<int> temp = numberPile;
            cout << "[";
            bool first = true;
            string numbers = "";
            while (!temp.empty()) {
                if (!first) numbers = ", " + numbers;
                numbers = to_string(temp.top()) + numbers;
                temp.pop();
                first = false;
            }
            cout << numbers << "]";
        }
        cout << endl << endl;
    }
    
    // Final answer!
    if (numberPile.size() == 1) {
        cout << "🎉 FINAL ANSWER: " << numberPile.top() << endl;
        cout << "That was fun! Your expression " << expression << " equals " << numberPile.top() << "!" << endl;
    } else {
        cout << "Hmm, something went wrong. I should have exactly one answer left!" << endl;
    }
    
    cout << "\n💡 How this works:" << endl;
    cout << "• I read left to right" << endl;
    cout << "• Numbers go into my memory pile" << endl;
    cout << "• When I see +,-,*,/, I take the top 2 numbers and do math" << endl;
    cout << "• The result goes back in my pile" << endl;
    cout << "• At the end, one number remains - that's the answer!" << endl;
    
    return 0;
}
