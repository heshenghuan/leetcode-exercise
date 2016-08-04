class Solutionn {
public:
    // this problem can simply be decomposed into 2 House Robber problems
    // Suppose there are n houses, since 0 and n-1 are now neighbors, we 
    // cannot rob them together, thus the solution is now the maximum of:
    //     1. Rob houses 0 to n-2;
    //     2. Rob houses 1 to n-1.
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return n?nums[0]:0;
        return max(robber(nums, 0, n-2), robber(nums, 1, n-1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int fa = 0, fb = 0;
        for(int i=l;i<=r;i++) {
            if(i%2)
                fb = max(fb+nums[i], fa);
            else
                fa = max(fa+nums[i], fb);
        }
        return max(fa, fb);
    }
};
