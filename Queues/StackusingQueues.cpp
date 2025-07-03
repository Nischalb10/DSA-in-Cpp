#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> q;

void push(int x) {
    q.push(x);
    int size = q.size();
    for (int i = 0; i < size - 1; ++i) {
        q.push(q.front());
        q.pop();
    }
}

int pop() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    int top = q.front();
    q.pop();
    return top;
}

int top() {
    if (q.empty()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return q.front();
}

bool empty() {
    return q.empty();
}

int main() {
    int choice;
    cout << "Operations:\n1 x -> push(x)\n2 -> pop()\n3 -> top()\n4 -> empty()\n0 -> exit\n";

    while (true) {
        cin >> choice;
        if (choice == 0) break;

        if (choice == 1) {
            int x;
            cin >> x;
            push(x);
        } else if (choice == 2) {
            cout << "Popped: " << pop() << endl;
        } else if (choice == 3) {
            cout << "Top: " << top() << endl;
        } else if (choice == 4) {
            cout << (empty() ? "Stack is empty" : "Stack is not empty") << endl;
        } else {
            cout << "Invalid command.\n";
        }
    }

    return 0;
}
