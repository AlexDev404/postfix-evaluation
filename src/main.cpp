// Name: Immanuel Garcia
// Topic: Assignment 2
// Teacher: Ms. Vernelle Sylvester
// Subject: Data Stuctures
// Date: 23th November, 2023

#include <iostream>
#include <stack>
#include <string>

// Stack class for storing integer values
class Stack {
public:
    void push(int value) {
        data.push(value);
    }

    int pop() {
        int value = data.top();
        data.pop();
        return value;
    }

    bool isEmpty() {
        return data.empty();
    }

private:
    std::stack<int> data;
};

// Function to calculate the result of an arithmetic operation
int calculate(char op, int x, int y) {
    switch (op) {
        case '+':{
            return y + x;
        }
        case '-':{
            return y - x;
        }
        case '*':{
            return y * x;
        }
        case '/':{
            return y / x;
        }
        case '^':{
            int result = 1;
            for (int i = 0; i < x; i++) {
                result *= y;
            }
            return result;
        }
        case '%':{
            return y % x;
        }
        default:{
            return 0;
        }
    }
}

// Function to evaluate a postfix expression and return the result
int evaluatePostfixExpression(const std::string& expression) {
    Stack stack; // Create an instance of the Stack class to store the operands
    for (char c : expression) { // Iterate through each character in the expression
        if (isdigit(c)) { // If the character is a digit
            stack.push(c - '0'); // Convert the character to an integer and push it onto the stack
        } else { // If the character is an operator
            int x = stack.pop(); // Pop the top operand from the stack
            int y = stack.pop(); // Pop the second operand from the stack
            stack.push(calculate(c, x, y)); // Perform the calculation using the operator and operands, and push the result onto the stack
        }
    }
    return stack.pop(); // Return the final result by popping it from the stack
}

int main() {
    std::string expression = "62+5*48/-";
    int result = evaluatePostfixExpression(expression);
    std::cout << "The answer to your expression is: " << result << std::endl;
    return 0;
}