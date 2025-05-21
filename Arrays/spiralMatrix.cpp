// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

#include<iostream>
#include<vector>

using namespace std;
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ret;
    
        while (!matrix.empty()) {
            // #1 Add the first row
            vector<int> firstRow = matrix.front();
            ret.insert(ret.end(), firstRow.begin(), firstRow.end());
            matrix.erase(matrix.begin());
    
            // #2 Add the last element of each remaining row
            if (!matrix.empty() && !matrix[0].empty()) {
                for (auto& row : matrix) {
                    ret.push_back(row.back());
                    row.pop_back();
                }
            }
    
            // #3 Add the last row in reverse
            if (!matrix.empty()) {
                vector<int> lastRow = matrix.back();
                ret.insert(ret.end(), lastRow.rbegin(), lastRow.rend());
                matrix.pop_back();
            }
    
            // #4 Add the first element of each row (bottom to top)
            if (!matrix.empty() && !matrix[0].empty()) {
                for (int i = matrix.size() - 1; i >= 0; i--) {
                    ret.push_back(matrix[i][0]);
                    matrix[i].erase(matrix[i].begin());
                }
            }
        }
    
        return ret;
        }

        int main() {
            int rows, cols;
            cout << "Enter number of rows and columns: ";
            cin >> rows >> cols;
        
            vector<vector<int>> matrix(rows, vector<int>(cols));
        
            cout << "Enter matrix elements row-wise:" << endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cin >> matrix[i][j];
                }
            }
        
            
            vector<int> result = spiralOrder(matrix);
        
            cout << "Spiral Order: ";
            for (int val : result) {
                cout << val << " ";
            }
            cout << endl;
        
            return 0;
        }
        