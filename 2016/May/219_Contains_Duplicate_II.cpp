class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> table;
        map<int, int>::iterator it;
        for(int i=0;i<nums.size();i++) {
            it = table.find(nums[i]);
            if(it != table.end()) {
                if(i - it->second <= k)
                    return true;
                else
                    table.erase(it);
            }
            // 总是将nums[i]加入table 也即会覆盖掉之前的下标 
            table.insert(pair<int, int>(nums[i], i));
        }
        return false;
    }
};