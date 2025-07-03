// Using a Stack - O(n+k) Time and O(k) Space
// The idea is to use an auxiliary stack. Remove(dequeue) the first k elements from the queue  and push them in a stack after this pop the elements from the stack and add(enqueue) them to the queue , after that simply remove(dequeue) the remaining n-k elements from the queue and add(enqueue) them back to the queue. 




#include <bits/stdc++.h>
using namespace std;

/* Function to reverse the first
   K elements of the Queue */
void reverseFirstK(queue<int>& q, int k)
{
    if (q.empty() == true || k > q.size())
        return;
    if (k <= 0)
        return;

    stack<int> s;

    /* Push the first K elements
       into a Stack*/
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    /* Enqueue the contents of stack
       at the back of the queue*/
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    /* Remove the remaining elements and
       enqueue them at the end of the Queue*/
    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

/* Utility Function to print the Queue */
void Print(queue<int>& q)
{
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    int k = 3;
    reverseFirstK(q, k);
    Print(q);
}

// Output
// 3 2 1 4 5 
// Time Complexity: O(n + k), Where 'n' is the total number of elements in the queue and 'k' is the number of elements to be reversed. This is because firstly the k elements from the queue is emptied into the stack and then added back to the queue from the stack after that first 'n-k' elements are emptied and enqueued back to the queue.
// Auxiliary Space: O(k) due to the stack used to store the first k elements.