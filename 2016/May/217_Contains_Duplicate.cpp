class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // solution 1, 40ms
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++) {
            if(nums[i-1] == nums[i]) return true;
        }
        return false;
        
        // solution 2, 96ms
        /* 
        map<int, int> int_map;
        for(int i=0;i<nums.size();i++) {
            if(int_map.count(nums[i])){
                return true;
            }
            int_map.insert(pair<int, int>(nums[i], i));    
        }
        return false;
        */
    }
};