/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Input: nums = [3,2,3]
Output: 3
*/



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algorithm
        int count = 0;
        int ele;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                count = 1;
                ele = nums[i];
            } else {
                if (nums[i] == ele) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        int cnt = 0;
        int ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele) {
                cnt++;
            }
            if (cnt > n / 2) {
                ans = ele;
            }
        }
        return ans;
    }
};