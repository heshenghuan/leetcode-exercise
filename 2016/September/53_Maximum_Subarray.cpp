class Solution {
public:
    // 一个定理，如果nums[i:j]最大，则对于任意k满足i<=k<=j，有nums[i:k] > 0
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = nums[0];
        int max = dp[0];
        for(int i=1;i<len;i++) {
            dp[i] = nums[i] + (dp[i-1] > 0?dp[i-1]:0);
            max = dp[i]>max ?dp[i]:max;
        }
        return max;
    }
};