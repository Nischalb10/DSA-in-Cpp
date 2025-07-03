💡 Intuition
------------

Reverse Polish Notation (RPN), or postfix notation, is a mathematical notation in which operators follow their operands. For example:

```
Expression:      2 + 1 * 3
RPN Equivalent:  ["2", "1", "+", "3", "*"]
```

The idea is to use a stack to evaluate the expression step by step.

* * * * *

🔍 Approach
-----------

1.  Initialize an empty stack.

2.  Iterate over each token:

    -   If the token is an operator (`+`, `-`, `*`, `/`), pop the top two elements from the stack, perform the operation, and push the result back.
    -   If the token is a number, convert it to an integer and push it onto the stack.
3.  After the loop, the result is the top element of the stack.

### ⚠️ Operator Order

Note that for non-commutative operations (like `-` and `/`), the second popped number is the left operand and the first popped number is the right operand (e.g., `b - a` or `b / a`).

* * * * *

✅ Code (C++)
------------

```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int index = 0;

        while (index < tokens.size()) {
            if (tokens[index] == "+") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a + b);
            }
            else if (tokens[index] == "-") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b - a);
            }
            else if (tokens[index] == "*") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(a * b);
            }
            else if (tokens[index] == "/") {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(b / a);
            }
            else {
                s.push(stoi(tokens[index]));
            }
            index++;
        }

        return s.top();
    }
};
```

* * * * *

🧠 Example
----------

```
Input:  ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```

* * * * *

⏱️ Time & Space Complexity
--------------------------

| Complexity | Value |
| --- | --- |
| Time | O(n) |
| Space | O(n) |

Where `n` is the number of tokens.