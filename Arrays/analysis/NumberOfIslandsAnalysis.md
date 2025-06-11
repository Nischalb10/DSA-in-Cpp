Approach
========

Actually, there isn't much to explation. We will check `4 direcitons`(`top`, `right`, `bottom`, `left`) from each place.

If we find `"1"`, we will keep the place(`row` and `column`).

But one problem is that we will keep the places where we already visited, so to prevent revisiting the same places, we also keep the places where we already visited.

* * * * *

⭐️ Points

-   Check `4 directions` from each place
-   If we find `"1"` and `the place is not visited yet`, keep it.

This algorithm will visit all `"1"` places with one BFS operation if the places are connected in the same island, that means every time we start new BFS operation, the place is one of new islands.

* * * * *

Easy!😄\
Let's see solution codes!

* * * * *

[](https://youtu.be/bU_dXCOWHls)

* * * * *

Complexity
==========

-   Time complexity: O(r∗c)

-   Space complexity: O(r∗c)

Python

JavaScript

Java

C++

```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        unordered_set<string> visited;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1' && visited.find(to_string(r) + "," + to_string(c)) == visited.end()) {
                    islands++;
                    bfs(grid, r, c, visited, directions, rows, cols);
                }
            }
        }

        return islands;
    }

private:
    void bfs(vector<vector<char>>& grid, int r, int c, unordered_set<string>& visited, vector<pair<int, int>>& directions, int rows, int cols) {
        queue<pair<int, int>> q;
        visited.insert(to_string(r) + "," + to_string(c));
        q.push({r, c});

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1' && visited.find(to_string(nr) + "," + to_string(nc)) == visited.end()) {
                    q.push({nr, nc});
                    visited.insert(to_string(nr) + "," + to_string(nc));
                }
            }
        }
    }
};
```

Step by Step Algorithm
======================

Step 1: Initialize Variables

```
class Solution:
def numIslands(self, grid: List[List[str]]) -> int:
    islands = 0
    visited = set()
    rows, cols = len(grid), len(grid[0])
```

-   `islands`: A counter to keep track of the number of islands found.
-   `visited`: A set to track the cells that have already been processed to avoid reprocessing them.
-   `rows` and `cols`: Store the dimensions of the grid. `rows` is the number of rows, and `cols` is the number of columns.

Step 2: Define the BFS Function

```
def bfs(r, c):
    q = deque()
    visited.add((r, c))
    q.append((r, c))
```

-   `bfs(r, c)`: A helper function that uses Breadth-First Search (BFS) to explore and mark all cells of the island starting from cell `(r, c)`.
-   `q = deque()`: Initialize a queue to process cells. `deque` is used for efficient popping from the front.
-   `visited.add((r, c))`: Mark the starting cell `(r, c)` as visited.
-   `q.append((r, c))`: Add the starting cell to the queue.

Step 3: Process the Queue

```
while q:
    row, col = q.popleft()
    directions = [[1,0],[-1,0],[0,1],[0,-1]]
```

-   `while q`: Process cells in the queue until it's empty.
-   `row, col = q.popleft()`: Dequeue the front cell.
-   `directions = [[1,0],[-1,0],[0,1],[0,-1]]`: Define the four possible movement directions (down, up, right, left).

Step 4: Explore Neighbors

```
for dr, dc in directions:
    r, c = row + dr, col + dc
    if 0 <= r < rows and 0 <= c < cols and grid[r][c] == "1" and (r, c) not in visited:
        q.append((r, c))
        visited.add((r, c))
```

-   `for dr, dc in directions`: Iterate through each direction.
-   `r, c = row + dr, col + dc`: Compute the new cell's coordinates.
-   `if 0 <= r < rows and 0 <= c < cols and grid[r][c] == "1" and (r, c) not in visited`: Check if the new cell is within bounds, is land (`"1"`), and has not been visited.
    -   If true, add the new cell to the queue and mark it as visited.

Step 5: Process Each Cell in Grid

```
for r in range(rows):
    for c in range(cols):
        if grid[r][c] == "1" and (r, c) not in visited:
            islands += 1
            bfs(r, c)
```

-   `for r in range(rows)`: Loop through each row.
-   `for c in range(cols)`: Loop through each column in the current row.
-   `if grid[r][c] == "1" and (r, c) not in visited`: Check if the cell is land and hasn't been visited.
    -   If true, increment the `islands` counter and call `bfs(r, c)` to mark all connected land cells of this island.

Step 6: Return the Result

```
return islands
```

-   After processing all cells, return the total count of `islands`.

* * * * *

Bonus
=====

If we can update `grid` directly, we can write solutions below.

Python

JavaScript

Java

C++

```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    islands++;
                    bfs(grid, r, c, rows, cols);
                }
            }
        }

        return islands;
    }

private:
    void bfs(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
```

`\
`
