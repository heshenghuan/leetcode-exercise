class Solution {
public:
    /*
     * 二分查找的思想，不过low和high不是数组下标二是查找duplicate number的范围
     * 对于给定的数组（n+1个数），取值范围是1~n，其中有一个数重复1次或多次，用二分查找的方法
     * 令low = 1，high = n，mid = (low + high)/2，统计数组中小于等于mid的数的个数count
     * 如果count <= mid 说明重复的数在[mid, high]这个范围内
     * 如果count > mid，说明重复的数在[low, mid]这个范围内
     */
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;  
        int mid = 0;
        while(low<high) {
            mid = (high + low) / 2;
            int cout = countMid(nums, mid);
            if (cout > mid) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
    int countMid(vector<int> nums, int mid) {
        int res = 0;
        for(auto val:nums) {
            if(val <= mid) res++;
        }
        return res;
    }
};