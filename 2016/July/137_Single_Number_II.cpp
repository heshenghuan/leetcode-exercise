class Solution {
public:
    /*
     * 将每一个int数当做一串32位长的0、1串，那么每一位上要么是0，要么是1
     * 统计每一位上1的数目，模3后的余数就是result这一位上的数
     * 该方法同样适用于Single Number
     */
    int singleNumber(vector<int>& nums) {
        if(!nums.size()) return 0;
        int res = 0;
        for(int i=0;i<32;i++) {
            int count = 0;
            int mask = 1 << i;
            for(auto val:nums) {
                if(val&mask) count++;
            }
            if(count % 3) res |= mask;
        }
        return res;
    }
};