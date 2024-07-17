/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};