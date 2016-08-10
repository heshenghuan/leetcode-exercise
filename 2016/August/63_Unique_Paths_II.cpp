class Solution {
public:
    // Solution 1, similar to #62 Unique Paths
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        dp[1][1] = 1;
        for (int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
    // A optimization of solution 1, do not store whole dp map
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> pre(n+1, 0);
        vector<int> cur(n+1, 0);
        pre[1] = 1;
        for (int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(!obstacleGrid[i-1][j-1])
                    cur[j] = pre[j] + cur[j-1];
                else cur[j] = 0;
            }
            swap(pre, cur);
        }
        return pre[n];
    }
};