class Solution {
public:
    // 利用二进制数的性质，2的幂仅有一个1，而其他数可以通过掩码运算得到
    // 如数字[5, 6, 7]，不大于且最接近它们的掩码是4(0100)
    // 而[5, 6, 7]的二进制形式分别为[0101, 0110, 0111]，减去掩码
    // 得到[0001, 0010, 0011]，且恰好它们只比掩码少一个1
    // 也即ans[5] = 1 + ans[5-4], ans[6] = 1 + ans[6-4], ans[7] = 1 + ans[7-4]
    // 注意当 i+1 等于 mask*2 时需要替换掩码，因为已经产生了最高位上的进位
    vector<int> countBits(int num) {
        vector<int> ans(1, 0);
        int mask = 1;
        for (int i=1;i<=num;i++) {
            ans.push_back(1+ans[i-mask]);
            if(i + 1 == mask * 2) mask <<= 1;
        }
        return ans;
    }
};