// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:

// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22
 

// Constraints:

// 1 <= tokens.length <= 104
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (const string& token : tokens) {
        if (token != "+" && token != "-" && token != "*" && token != "/") {
            st.push(stoi(token));
        } else {
            int x2 = st.top(); st.pop();
            int x1 = st.top(); st.pop();
            int r = 0;
            if (token == "+") r = x1 + x2;
            else if (token == "-") r = x1 - x2;
            else if (token == "*") r = x1 * x2;
            else if (token == "/") r = x1 / x2;
            st.push(r);
        }
    }
    return st.top();
}

int main() {
    cout << "Enter RPN expression (space-separated tokens): ";
    string line;
    getline(cin, line);

    istringstream iss(line);
    string token;
    vector<string> tokens;

    while (iss >> token) {
        tokens.push_back(token);
    }

    int result = evalRPN(tokens);
    cout << "Result: " << result << endl;
    return 0;
}
