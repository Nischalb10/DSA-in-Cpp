Intuition
=========

Since the problem talks about frequency of elements, the use of a hash map (unordered_map) came to mind immediately.\
Also, since we need to return the top k frequent elements, a max heap (priority queue) is ideal to efficiently retrieve the most frequent items.

Approach
========

-   Use an unordered map to count the frequency of each element in the array.

-   Push each (frequency, element) pair into a max heap (priority queue).

-   To save memory, clear the original array and hash map after storing values.

-   Pop the top k elements from the heap and push them into the result vector.

-   Return the result.\
    You can also solve this using sort() + custom comparator, here I have used the heap.

Complexity
==========

-   Time complexity:\
    O(n) for frequency map creation + O(N log N) for heap insertion + O(k) for extracting top elements

    Overall: O(n + N log N + k)

-   Space complexity:\
    O(N) for the frequency map and heap (where N is number of unique elements)