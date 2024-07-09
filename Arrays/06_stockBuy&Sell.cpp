/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Input: prices = [7,1,5,3,6,4]
Output: 5
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_diff=0;
        int minm_val=prices[0];
        for(int i=1;i<prices.size();i++){
            max_diff=max(max_diff,prices[i]-minm_val);
            minm_val=min(minm_val,prices[i]);
        }
        if(max_diff<0)
        return 0;
        else
        return max_diff;
    }
};