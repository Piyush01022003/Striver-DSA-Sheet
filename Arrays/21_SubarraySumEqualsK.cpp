/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,1,1], k = 2
Output: 2
*/



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int, int> prefix_sum_count;
    int prefix_sum = 0, result = 0;

    prefix_sum_count[0] = 1; // Initialize with 0 to count the cases where prefix_sum - k == 0.

    for (int i = 0; i < nums.size(); i++) {
        prefix_sum = prefix_sum + nums[i];

        if (prefix_sum_count.find(prefix_sum - k) != prefix_sum_count.end()) {
            result += prefix_sum_count[prefix_sum - k];
        }

        prefix_sum_count[prefix_sum]++;
    }

    return result;
    }
};