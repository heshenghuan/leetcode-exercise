class Solution {
public:
    /*
    * dist 表示当前能跳到的最远距离，下标i<=dist表示能调到，i>dist表示跳不到
    * 因此，最终若dist<(n-1)表示无法跳到end position，否则可以。
    */
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return true;
        int dist = 0;
        for(int i=0;i<n&&i<=dist;i++) {
            dist = max(nums[i]+i, dist);
        }
        return !(dist<(n-1));
    }
};