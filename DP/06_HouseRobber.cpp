/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

//Memoization Code
class Solution {
private:
    int robHelper(vector<int> & nums, int ind, vector<int> &dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + robHelper(nums, ind - 2, dp);
        int notPick =  robHelper(nums, ind - 1, dp);

        return dp[ind] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return robHelper(nums, n-1, dp);
    }
};

//Tabulation Code //Space optimized
class Solution {
public:
    int rob(vector<int>& nums) {
        int n =  nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for(int i=1; i<n; i++){
            int take = nums[i] + prev2;
            int notTake = prev;

            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};


