#include <iostream>
#include <stack>
#include <string>

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

int evaluatePostfixExpression(const std::string& expression) {
    Stack stack;
    for (char c : expression) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else {
            int x = stack.pop();
            int y = stack.pop();
            stack.push(calculate(c, x, y));
        }
    }
    return stack.pop();
}

int main() {
    std::string expression = "62+5*48/-";
    int result = evaluatePostfixExpression(expression);
    std::cout << "The answer to your expression is: " << result << std::endl;
    return 0;
}