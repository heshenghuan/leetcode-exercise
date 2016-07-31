class Solution {
public:
    /*
     * 利用动态规划解题，从1开始，用两个循环，把1~n中的各个数的答案递推出来
     * 对任意一个平方数i2，所有比其大的数j，有
     * dp[j] = min(dp[j], dp[j-i2]+1)
     */
    int numSquares(int n) {
        static vector<int> dp {0};
        int m = dp.size();
        dp.resize(max(m, n+1), INT_MAX);
        for(int i=1, i2; (i2 = i*i)<=n; ++i) {
            for(int j=i2; j<=n; ++j) {
                if(dp[j] > dp[j-i2] + 1)
                    dp[j] = dp[j-i2] + 1;
            }
        }
        return dp[n];
    }
};