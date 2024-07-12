/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

Input: s = "abcabcbb"
Output: 3
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char,int>mp;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }
            mp[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};