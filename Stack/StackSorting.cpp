#include <iostream>
#include <stack>
using namespace std;

// Function to sort the elements of a stack
void sortStack(stack<int>& input) {
    stack<int> tempStack;

    while (!input.empty()) {
        // Pop out the top element
        int tmp = input.top();
        input.pop();

        // While temporary stack is not empty and top is greater than tmp
        while (!tempStack.empty() && tempStack.top() > tmp) {
            input.push(tempStack.top());
            tempStack.pop();
        }

        // Push tmp in tempStack
        tempStack.push(tmp);
    }

    // Transfer sorted elements back to input stack (optional)
    while (!tempStack.empty()) {
        input.push(tempStack.top());
        tempStack.pop();
    }
}

// Function to print elements of a stack
void printStack(stack<int> s) {
    cout << "Stack from top to bottom: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> myStack;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        myStack.push(val);
    }

    cout << "Original Stack:\n";
    printStack(myStack);

    sortStack(myStack);

    cout << "Sorted Stack:\n";
    printStack(myStack);

    return 0;
}
