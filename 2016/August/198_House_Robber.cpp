class Solution {
public:
    /*
     * f(0) = nums[0]
     * f(1) = max(nums[1], nums[0])
     * f(2) = max(f(1), f(0)+nums[2])
     * f(n) = max(f(n-1), f(n-2)+nums[n])
     */
    int rob(vector<int>& nums) {
        // Only use two variable to store the result of f(n)
        // fa represent f(n) when n is an even number
        // fb represent f(n) when n is an odd number
        int fa = 0, fb = 0;

        for(int i=0;i<nums.size();i++) {
            if(i%2)
                fb = max(fb+nums[i], fa);
            else
                fa = max(fa+nums[i], fb);
        }
        return max(fa, fb);
    }
};