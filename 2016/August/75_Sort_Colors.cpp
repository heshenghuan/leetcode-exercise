class Solution {
public:
    // Solution 1, counting sort
    void sortColors(vector<int>& nums) {
        int count[] = {0, 0, 0};
        for(auto v:nums) {
            count[v]++;
        }
        nums.clear();
        nums.resize(count[0], 0);
        nums.resize(count[0]+count[1], 1);
        nums.resize(count[0]+count[1]+count[2], 2);
    }

    // Solution 2(not my original), an one-pass algorithm, swap sort.
    // See more detail on https://discuss.leetcode.com/topic/36832/sharing-c-solution-with-good-explanation/2
    void sortColors2(vector<int>& nums) {
        int tmp = 0, low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                tmp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = tmp;
                mid++;
                low++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else if (nums[mid] == 2) {
                tmp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = tmp;
                high--;
            }
        }
    }
};