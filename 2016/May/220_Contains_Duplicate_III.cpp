class Solution {
public:
    // notice: |nums[i] - nums[j]| <= t ---> nums[i] - t <= nums[j] <= nums[i] + t
    // for each nums[i] find a value which >= (nums[i] - t), 
    // if the value exists, check if it is not greater than (nums[i] + t) 
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> tree; // this the BST of k-size window
        int len = nums.size();
        for(int i=0;i<len;i++) {
            if(i > k) tree.erase(nums[i - k - 1]); //every time remove a element beyond window 
            set<int>::iterator it = tree.lower_bound(nums[i] - t); // find a value not less than (nums[i] - t)
            if(it!=tree.end() && *it -nums[i] <= t) // exists, check if it is not greater than (nums[i] + t)
                return true; // YES!
            tree.insert(nums[i]); // keep the size of window
        }
        return false; // NO...
    }
};