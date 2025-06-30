// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

 

// Example 1:


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // Append the remaining nodes
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }

    return dummyNode->next;
}

// Create linked list from user input
ListNode* createList(int n) {
    if (n == 0) return nullptr;

    int val;
    cout << "Enter value for node 1: ";
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* tail = head;

    for (int i = 2; i <= n; ++i) {
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    return head;
}

// Print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n1, n2;

    cout << "Enter number of nodes in first sorted list: ";
    cin >> n1;
    ListNode* list1 = createList(n1);

    cout << "Enter number of nodes in second sorted list: ";
    cin >> n2;
    ListNode* list2 = createList(n2);

    ListNode* merged = mergeTwoLists(list1, list2);

    cout << "Merged sorted list: ";
    printList(merged);

    return 0;
}
