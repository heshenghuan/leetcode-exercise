class Solution {
public:
    /*
     * 解题思路：模拟人在寻找最长连续序列的过程
     * 1. 对于nums中的一个数 value，在nums中寻找 value-1（转2） 或 value+1（转3）
     * 2. 将value - 1作为新的value，并继续往减小方向找数，每找到一个序列长度+1
     * 3. 将value + 1作为新的value，并继续往增大方向找数，每找到一个序列长度+1
     * 4. 每次找到一个数都可以将其从map中划掉，因为连续的序列中的数没有必要找第二遍
     * 5. 每次对一个value搜索完毕后，ans = max(ans, cur)
     * 6. 当所有数都搜索完毕后，返回ans即可
     *
     * 参考: http://www.tuicool.com/articles/B7FBb2
     */
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> maps;
        int ans = 0, cur = 0;
        for(int i = 0; i < nums.size(); i++) {
            maps.insert(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++) {
            if(maps.find(nums[i]) != maps.end()){
                maps.erase(nums[i]);
                cur = 1;
                int left = nums[i] - 1;
                while(maps.find(left) != maps.end()) {
                    maps.erase(left);
                    cur++;
                    left--;
                }
                int right = nums[i] + 1;
                while(maps.find(right) != maps.end()) {
                    maps.erase(right);
                    cur++;
                    right++;
                }
                ans = max(cur, ans);
            }
        }
        return ans;
    }
};