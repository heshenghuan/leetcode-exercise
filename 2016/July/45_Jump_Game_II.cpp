class Solution {
public:
    /*
     * BFS，使用end记录当前能到的结点， maxend为当前能到范围内计算得到的可达最远范围
     * step记录步数，每一次move都遍历所有能到的结点，更新maxend
     * 一旦maxend >= n-1返回此时的step即可
     */
    int jump(vector<int>& nums) {
        int n = nums.size(), step = 0, end = 0, maxend = 0, i = 0;
        while(end < n - 1) {
            ++step;
            for(;i<=end;i++) {
                maxend = max(maxend, nums[i] + i);
                if (maxend >= n - 1) return step;
            }
            if(end == maxend) break; // 若假设总能到达最后，则不需要这一句
            end = maxend;
        }
        return n == 1 ? 0 : -1; // 若假设总能到达最后，则改为返回step
    }
};