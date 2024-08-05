//You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

//space optimised code derived from previous
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n,0);

        for(int i = 0; i < m; i++) {
            vector<int> curr(n,0);
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                    }
                else if(i == 0 && j == 0) {
                    curr[j] = 1;
                }else {
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

