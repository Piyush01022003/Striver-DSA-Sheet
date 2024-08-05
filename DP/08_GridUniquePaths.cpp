//There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.  Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.


class Solution {
public:
    int uniquePaths(int m, int n) {
        // Base case: if we're at the first row or first column, there's only one path
        if (m == 1 || n == 1) {
            return 1;
        }
        // Recursive case: the number of unique paths to (m, n) is the sum of the paths to (m-1, n) and (m, n-1)
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};


//recursive soln 2  // time 2^(m*n)
class Solution {
private:
    int countPaths(int i, int j) {
        // Base case: If we're at the first cell, there's only one path to it
        if (i == 0 && j == 0) {
            return 1;
        }
        // Base case: If out of bounds, return 0
        if (i < 0 || j < 0) {
            return 0;
        }
        
        // Recursive case: Sum of paths from the top and from the left
        int up = countPaths(i - 1, j);
        int left = countPaths(i, j - 1);

        return up + left;
    }

public:
    int uniquePaths(int m, int n) {
        return countPaths(m - 1, n - 1);
    }
};


//memoisation  //O(m*n) time, O(m-1 + n-1) + O(m*n) space recursion + dp
class Solution {
private:
    int countPaths(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];

        int up = countPaths(i - 1, j, dp);
        int left = countPaths(i, j - 1, dp);

        return dp[i][j] = up + left;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(m - 1, n - 1, dp);
    }
};

//tabulation 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[0][0] = 1;
                } else {
                    int up = 0, left = 0;

                    if(i > 0)  up = dp[i - 1][j];
                    if(j > 0)  left = dp[i][j - 1];

                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// space optimised
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);

        for(int i = 0; i < m; i++) {
            vector<int> curr(n,0);
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int up = 0, left = 0;

                    if(i > 0)  up = prev[j];
                    if(j > 0)  left =  curr[j - 1];

                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};

