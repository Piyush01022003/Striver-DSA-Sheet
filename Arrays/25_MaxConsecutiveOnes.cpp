/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Input: nums = [1,1,0,1,1,1]
Output: 3
*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current=0,result=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                current=0;
            }
            else{
                current++;
                result=max(result,current);
            }
        }
        return result;
    }
};