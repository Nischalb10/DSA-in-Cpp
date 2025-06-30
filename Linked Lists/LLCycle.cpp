// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

 

// Example 1:


// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
// Example 2:


// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
// Example 3:


// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.
 

// Constraints:

// The number of the nodes in the list is in the range [0, 104].
// -105 <= Node.val <= 105
// pos is -1 or a valid index in the linked-list.
 

// Follow up: Can you solve it using O(1) (i.e. constant) memory?
#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Detect cycle using Floyd's Tortoise and Hare algorithm
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

// Create a linked list with optional cycle
ListNode* createList(int n, int pos) {
    if (n == 0) return nullptr;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* cycleNode = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        ListNode* newNode = new ListNode(val);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }

        if (i == pos)
            cycleNode = newNode;
    }

    // Create cycle if pos is valid
    if (pos != -1 && tail)
        tail->next = cycleNode;

    return head;
}

int main() {
    int n, pos;
    cout << "Enter number of nodes in the linked list: ";
    cin >> n;

    cout << "Enter position to link the tail to (0-based index, -1 for no cycle): ";
    cin >> pos;

    ListNode* head = createList(n, pos);

    if (hasCycle(head)) {
        cout << "Cycle detected in the linked list.\n";
    } else {
        cout << "No cycle in the linked list.\n";
    }

    return 0;
}
