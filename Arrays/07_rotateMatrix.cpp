/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose the matrix and reverse the rows
        int n= matrix.size();
        for(int i=0;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};