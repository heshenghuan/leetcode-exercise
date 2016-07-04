class Solution {
public:
    /*
     * 利用异或运算的性质：a ^ b = b ^ a, 0 ^ a = a 
     */
    int singleNumber(vector<int>& nums) {
        int res = 0;
        if(nums.size() == 0) return res;
        for(auto val:nums) {
            res = res ^ val;
        }
        return res;
    }
};