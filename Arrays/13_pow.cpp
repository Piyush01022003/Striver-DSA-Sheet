/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Input: x = 2.00000, n = 10
Output: 1024.00000
*/


class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long n1 = n; 
        if(n1<0)  n1 = -1 * n1;  //converting -ve to +ve n;
        while(n1>0){
            if(n1 % 2 == 0){
                x = x * x;
                n1 = n1 / 2;
            }else{
                ans = ans * x;
                n1 = n1 - 1;
            }
        }
        if(n<0) ans = (double)1 / (double)ans;
        return ans;
    }
};