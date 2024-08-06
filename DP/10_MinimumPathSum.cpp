/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.*/


// Recursion O(2 ^ m*n) time O(m-1+n-1) space
class Solution {
private:
    int pathSum(int i, int j, vector<vector<int>>& grid){
        if(i == 0 && j == 0){
            return  grid[0][0];
        }
        
        int up = INT_MAX;
        int left = INT_MAX;
        if(i>0)
        up = grid[i][j] + pathSum(i-1, j, grid);
        if(j>0)
        left = grid[i][j] + pathSum(i, j-1, grid);

        return min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return pathSum(m-1, n-1, grid);
    }
};

//Memoisation O(m*n) time O(m*n) + O(m-1 + n-1) space
class Solution {
private:
    int pathSum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0){
            return  grid[0][0];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int up = INT_MAX;
        int left = INT_MAX;
        if(i>0)
        up = grid[i][j] + pathSum(i-1, j, grid, dp);
        if(j>0)
        left = grid[i][j] + pathSum(i, j-1, grid, dp);

        return dp[i][j] = min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return pathSum(m-1, n-1, grid, dp);
    }
};

//tabulation O(m*n) time O(m*n) space
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(i == 0 && j == 0) dp[0][0] = grid[0][0];
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0) up = grid[i][j] + dp[i-1][j];
                    if(j>0) left = grid[i][j] + dp[i][j-1];

                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[m-1][n-1];
    }
};

//space optimisaton O(m*n) time O(n) space
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, -1);

        for(int i=0; i<m; i++){
            vector<int> curr(n, -1);
            for(int j=0; j<n; j++){

                if(i == 0 && j == 0) curr[j] = grid[0][0];
                else{
                    int up = INT_MAX;
                    int left = INT_MAX;
                    if(i>0) up = grid[i][j] + prev[j];
                    if(j>0) left = grid[i][j] + curr[j-1];

                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }

        return prev[n-1];
    }
};