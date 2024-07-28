/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
*/

/*
Recursive TLE solution

class Solution {
private:
    int minCost(vector<int> &cost, int n){
        if(n<0) return 0;
        if(n==0 || n==1) return cost[n];
        return cost[n] + min(minCost(cost, n-1), minCost(cost, n-2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return  min(minCost(cost, n-1), minCost(cost, n-2));
    }
};
*/
// Dp solution
class Solution {
public:
    vector<int> dp;
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n, 0);
        return min(minCost(cost, n-1), minCost(cost, n-2));
    }
    
private:
    int minCost(vector<int>& cost, int n) {
        if (n < 0) return 0;
        if (n == 0 || n == 1) return cost[n];
        if (dp[n] != 0) return dp[n];
        dp[n] = cost[n] + min(minCost(cost, n-1), minCost(cost, n-2));
        return dp[n];
    }
};

//Getting rid of recursive  stack

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            if (i < 2) {
                dp[i] = cost[i];
            } else {
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
            }
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

/*
// Bottom up computation - O(n) time, O(1) space  Java Code
public int minCostClimbingStairs(int[] cost) {
	int n = cost.length;
	int first = cost[0];
	int second = cost[1];
	if (n<=2) return Math.min(first, second);
	for (int i=2; i<n; i++) {
		int curr = cost[i] + Math.min(first, second);
		first = second;
		second = curr;
	}
	return Math.min(first, second);
}
*/