// There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

// You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

// Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

// Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

 

// Example 1:

// Input: tickets = [2,3,2], k = 2

// Output: 6

// Explanation:

// The queue starts as [2,3,2], where the kth person is underlined.
// After the person at the front has bought a ticket, the queue becomes [3,2,1] at 1 second.
// Continuing this process, the queue becomes [2,1,2] at 2 seconds.
// Continuing this process, the queue becomes [1,2,1] at 3 seconds.
// Continuing this process, the queue becomes [2,1] at 4 seconds. Note: the person at the front left the queue.
// Continuing this process, the queue becomes [1,1] at 5 seconds.
// Continuing this process, the queue becomes [1] at 6 seconds. The kth person has bought all their tickets, so return 6.
// Example 2:

// Input: tickets = [5,1,1,1], k = 0

// Output: 8

// Explanation:

// The queue starts as [5,1,1,1], where the kth person is underlined.
// After the person at the front has bought a ticket, the queue becomes [1,1,1,4] at 1 second.
// Continuing this process for 3 seconds, the queue becomes [4] at 4 seconds.
// Continuing this process for 4 seconds, the queue becomes [] at 8 seconds. The kth person has bought all their tickets, so return 8.
 

// Constraints:

// n == tickets.length
// 1 <= n <= 100
// 1 <= tickets[i] <= 100
// 0 <= k < n
#include <iostream>
#include <vector>
#include <algorithm> // for min
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int total = 0;
    for (int i = 0; i < tickets.size(); ++i) {
        if (i <= k) {
            total += min(tickets[i], tickets[k]);
        } else {
            total += min(tickets[i], tickets[k] - 1);
        }
    }
    return total;
}

int main() {
    int n, k;
    cout << "Enter number of people in queue: ";
    cin >> n;

    vector<int> tickets(n);
    cout << "Enter the number of tickets each person wants:\n";
    for (int i = 0; i < n; ++i) {
        cin >> tickets[i];
    }

    cout << "Enter the index (k) of the person you care about: ";
    cin >> k;

    int result = timeRequiredToBuy(tickets, k);
    cout << "Time required for person at index " << k << " to finish buying: " << result << endl;

    return 0;
}
