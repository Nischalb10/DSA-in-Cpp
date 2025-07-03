// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

 

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
 

// Constraints:

// -231 <= val <= 231 - 1
// Methods pop, top and getMin operations will always be called on non-empty stacks.
// At most 3 * 104 calls will be made to push, pop, top, and getMin.
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> s;
stack<int> minS;

void push(int val) {
    s.push(val);
    if (minS.empty() || val <= minS.top()) {
        minS.push(val);
    }
}

void pop() {
    if (!s.empty()) {
        if (s.top() == minS.top()) {
            minS.pop();
        }
        s.pop();
    }
}

int top() {
    if (!s.empty()) return s.top();
    return -1; // or throw error
}

int getMin() {
    if (!minS.empty()) return minS.top();
    return -1; // or throw error
}

int main() {
    int q;
    cout << "Enter number of operations: ";
    cin >> q;
    cout << "Commands:\n 1 x => push(x)\n 2 => pop()\n 3 => top()\n 4 => getMin()\n";
    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x;
            cin >> x;
            push(x);
        } else if (cmd == 2) {
            pop();
        } else if (cmd == 3) {
            cout << "Top: " << top() << endl;
        } else if (cmd == 4) {
            cout << "Min: " << getMin() << endl;
        } else {
            cout << "Invalid command.\n";
        }
    }
    return 0;
}
