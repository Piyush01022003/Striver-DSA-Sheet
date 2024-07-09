//Pascal Triangle 
/*
Given an integer numRows, return the first numRows of Pascal's triangle.
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

class Solution {
private:
    long long nCr(int n, int r){
        if (r == 0) return 1; // Base case
        long long res = 1;
        for(int i = 0; i < r; i++){
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    vector<int> getRow(int rowIndex) {
        // for row index i, no. of elements will be i+1;
        vector<int> ans;
        for(int i = 0; i <= rowIndex; i++){
            long long temp = nCr(rowIndex, i);
            ans.push_back(temp);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;
        for(int i=0;i<numRows;i++){
            vector<int>row= getRow(i);
            pascal.push_back(row);
        }
        return pascal;
    }
};

