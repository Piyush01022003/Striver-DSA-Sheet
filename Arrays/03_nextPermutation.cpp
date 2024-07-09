//Next Permutation
/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].Given an array of integers nums, find the next permutation of nums.

Input: nums = [1,1,5]
Output: [1,5,1]
*/

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int k=-1,n=arr.size(),l=n-1;
        for(int i=arr.size()-1;i>0;i--){
            if(arr[i-1]<arr[i]){
                k=i-1;
                break;
            }
        }
        if(k==-1){
            reverse(arr.begin(),arr.end());
        }
        else{
            for(int i=arr.size()-1;i>k;i--){
                if(arr[i]>arr[k]){
                    l=i;
                    break;
                }
            }
            swap(arr[k],arr[l]);
            reverse(arr.begin()+k+1,arr.end());
        }
    }
};