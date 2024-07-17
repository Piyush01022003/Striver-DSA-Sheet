/*
You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

Return the string that represents the kth largest integer in nums.

Note: Duplicate numbers should be counted distinctly. For example, if nums is ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, and "1" is the third-largest integer.

Input: nums = ["3","6","7","10"], k = 4
Output: "3"
*/

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        // Custom comparator for the priority queue to handle strings as large
        // numbers
        auto cmp = [](const string& a, const string& b) {
            if (a.size() == b.size()) {
                return a >
                       b; // For same length strings, compare lexicographically
            }
            return a.size() > b.size(); // Otherwise, compare by length
        };

        // Declaring the min-heap with the custom comparator
        priority_queue<string, vector<string>, decltype(cmp)> minHeap(cmp);

        for (const string& num : nums) {
            minHeap.push(num); // Push current number to the heap
            if (minHeap.size() > k) {
                minHeap
                    .pop(); // If heap size exceeds k, pop the smallest element
            }
        }

        return minHeap.top(); // The top element is the k-th largest number
    }
};
