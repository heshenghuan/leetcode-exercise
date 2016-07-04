class Solution {
public:
    /*
     * 也是利用异或运算的性质，算法中的result = res[0] ^ res[1]
     * 找到result中为1的最低位，按此位将原数组分为两个子数组，则res[0]和res[1]分别在不同的子数组中
     */
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() < 2) return vector<int> ();
        else if(nums.size() == 2) return nums;
        
        vector<int> res(2, 0);
        int result = 0;
        for(auto val:nums) {
            result ^= val;
        }
        int n = result & (~(result - 1));
        for(auto val:nums) {
            if(n&val) res[0] ^= val;
            else res[1] ^= val;
        }
        return res;
    }
};