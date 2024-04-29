#include <iostream>
#include <stack>
#include <string>
#include <cctype>  // For isdigit

using namespace std;

class InfixToPostfixConverter {
private:
    stack<char> operators;

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

public:
    string convert(const string& infix) {
        string output;
        for (int i = 0; i < infix.length(); i++) {
            if (infix[i] == ' ') continue;  // Skip spaces

            if (isdigit(infix[i])) {
                // If the token is a number (or a digit), add it to the output
                output += infix[i];
                while (i + 1 < infix.length() && isdigit(infix[i + 1])) {
                    output += infix[++i];  // Add subsequent digits to the output
                }
                output += ' ';  // Append a space to separate numbers
            } else if (infix[i] == '(') {
                operators.push(infix[i]);  // Push '(' to stack
            } else if (infix[i] == ')') {
                // Until '(' is encountered, resolve the stack
                while (!operators.empty() && operators.top() != '(') {
                    output += operators.top();
                    output += ' ';
                    operators.pop();
                }
                operators.pop();  // Pop '(' from the stack
            } else {
                // Operator encountered
                while (!operators.empty() && precedence(operators.top()) >= precedence(infix[i])) {
                    output += operators.top();
                    output += ' ';
                    operators.pop();
                }
                operators.push(infix[i]);  // Push current operator to stack
            }
        }

        // Pop all remaining operators in the stack
        while (!operators.empty()) {
            output += operators.top();
            output += ' ';
            operators.pop();
        }

        return output;
    }
};

int main() {
   InfixToPostfixConverter converter;
    string exp;
    cout<<"Enter the expression"<<endl;
    cin>>exp;
    cout << "Infix Expression: " << exp << endl;
    cout << "Postfix Expression: " << converter.convert(exp) << endl;
    return 0;
}
