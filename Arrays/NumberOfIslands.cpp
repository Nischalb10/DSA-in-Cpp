// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

void bfs(vector<vector<char>>& grid, int r, int c,
         unordered_set<string>& visited, vector<pair<int, int>>& directions,
         int rows, int cols) {
    queue<pair<int, int>> q;
    visited.insert(to_string(r) + "," + to_string(c));
    q.push({r, c});

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (auto [dr, dc] : directions) {
            int nr = row + dr;
            int nc = col + dc;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                grid[nr][nc] == '1' &&
                visited.find(to_string(nr) + "," + to_string(nc)) ==
                    visited.end()) {
                q.push({nr, nc});
                visited.insert(to_string(nr) + "," + to_string(nc));
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int islands = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    unordered_set<string> visited;

    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == '1' &&
                visited.find(to_string(r) + "," + to_string(c)) ==
                    visited.end()) {
                islands++;
                bfs(grid, r, c, visited, directions, rows, cols);
            }
        }
    }

    return islands;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns in the grid: ";
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    cout << "Enter grid row by row (0 or 1):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
