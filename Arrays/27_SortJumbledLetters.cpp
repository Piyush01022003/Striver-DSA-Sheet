/*
Sort the Jumbled Numbers

You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.
The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.


Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
Output: [338,38,991]
*/

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> val(n, pair<int, int>(0, 0));

        for (int i = 0; i < n; ++i) { 
            int num = nums[i], j = 0, ans = 0;
            if (num == 0) {
                ans = mapping[num];
            } else {
                while (num > 0) {
                    ans += pow(10, j) * mapping[num % 10];
                    num /= 10;
                    ++j;
                }
            }
            val[i].first = ans;
            val[i].second = i;
        }
        
        sort(val.begin(), val.end());
        vector<int> res(n);

        for (int i = 0; i < n; ++i) { 
            res[i] = nums[val[i].second];
        }

        return res;
    }
};