class Solution {
public:
    /*
     * 利用动态规划解题，从1开始，用两个循环，把1~n中的各个数的答案递推出来
     * 对任意一个平方数i2，所有比其大的数j，有
     * dp[j] = min(dp[j], dp[j-i2]+1)
     */
    int numSquares(int n) {
        static vector<int> dp {0}; // using static here to reduce time cost
        int m = dp.size();
        dp.resize(max(m, n+1), INT_MAX); // resize函数只对新添加在末尾的元素赋值为INT_MAX，其他元素不变
        for(int i=1, i2; (i2 = i*i)<=n; ++i) {
            for(int j=max(m,i2); j<=n; ++j) {
                // max(m, i2)很重要，能快很多倍
                // 因为dp是static声明的，一直存在内存中，当重复调用时m会改变（增大）
                // 若m>i2，则可以避免重复计算
                if(dp[j] > dp[j-i2] + 1)
                    dp[j] = dp[j-i2] + 1;
            }
        }
        return dp[n];
    }
};