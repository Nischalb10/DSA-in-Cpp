Approach 1 - Using Heap
=======================

Intuition
=========

The goal is to schedule tasks with a cooldown period `n` such that the same type of task cannot be run within `n` intervals. Idle slots may be required.

We aim to minimize the total time, and a greedy approach using a max heap (priority queue) helps us always schedule the most frequent remaining task first.

Approach
========

1.  Count the frequency of each task.
2.  Push all non-zero frequencies into a max heap.
3.  In each round of size `n + 1`, pick the `n + 1` most frequent tasks and execute them:
    -   Reduce their frequency (since they're processed once).
    -   Store the remaining frequency if it's still greater than 0.
4.  After each round:
    -   If the heap is empty, add only the actual number of tasks executed (`temp.size()`).
    -   Otherwise, it means we needed idle time, so we add a full round of `n + 1`.

Time Complexity
===============

-   O(N + 26 * log 26) = O(N) where `N` is the number of tasks.
    -   Counting frequencies takes O(N).
    -   Heap operations are constant since max size is 26 (number of capital letters).

Space Complexity
================

-   O(1): Fixed size array for frequency (`26`).
-   Priority queue size is also limited to 26.

Note
====

-   This approach greedily schedules the most frequent tasks first and groups them into cycles of size `n + 1`.