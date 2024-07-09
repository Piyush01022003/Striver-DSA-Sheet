/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
*/

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int result=arr[0];
        int prev_sum=arr[0];
        int curr_sum=0;
        int n=arr.size();
        for(int i=1;i<n;i++){
            curr_sum=max(arr[i],arr[i]+prev_sum);
            prev_sum=curr_sum;
            result=max(result,curr_sum);
        }
        return result;
    }
};