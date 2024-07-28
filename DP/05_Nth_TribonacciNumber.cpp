/*
The Tribonacci sequence Tn is defined as follows: 
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
Given n, return the value of Tn.

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
*/

/*
// Recursive TLE code
class Solution {
public:
    int tribonacci(int n) {
        if(n <= 0) return 0;
        if(n == 1 || n == 2) return 1;

        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};
*/

/*
// iterative dp solution
class Solution {
public:
    int tribonacci(int n) {
        if(n <= 0) return 0;
        if(n == 1 || n == 2) return 1;

        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
};
*/

class Solution {
public:
    int tribonacci(int n) {
        if (n < 3) {
            return n == 0 ? 0 : 1;
        }

        int a = 0, b = 1, c = 1;

        for (int i = 2; i < n; i++) {
            int temp = a + b + c;
            a = b;
            b = c;
            c = temp;
        }
        return c;
    }
};