/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Input: nums = [100,4,200,1,3,2]
Output: 4
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int result=1;
        if(nums.size()==0){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            int curr=1;int j=1;
            if(s.find(nums[i]-1)==s.end()){
                while(s.find(nums[i]+j)!=s.end()){
                    curr++;
                    j++;
                }
                result=max(result,curr);
            }
        }
        return result;
        
    }
};