The key idea in this problem is that we must only consider paths with at most k stops.\
This means even if a shorter (cheaper) path exists that exceeds k stops, it should be ignored.\
Therefore, we need to process paths with fewer stops first.

To ensure we always pick the best (cheapest) path within the allowed number of stops,\
we use a distance array. This array keeps track of the minimum cost to reach each node.\
We only update the cost and continue exploring a neighbor if:

-   The number of stops used so far is ≤ k, and
-   The new path offers a cheaper cost than previously recorded.

This is why the distance array is critical --- it helps us avoid revisiting costlier or invalid paths\
and ensures we only track the best routes that meet the stop constraint.