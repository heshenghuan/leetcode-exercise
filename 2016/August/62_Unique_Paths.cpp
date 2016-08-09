class Solution {
public:
    // 很简单的一道题，题目中说了机器人只能向下或向右移动
    // 那么对于任意一个点，只能从其上方或左方的点到达此处
    // 于是得到dp方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]
    // 边界情况也很好判断，起点dp[0][0] = 1，边缘dp[0][j]=dp[i][0]=1
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n, 1));
        for (int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};