class Solution {
public:
    /*
    * 给定的数组的范围是0~n，利用求和公式求出0~n的和
    * 最后依次减去nums中的每个数就可求出Missing Number
    */
    int missingNumber(vector<int>& nums) {
        int m = (nums.size()+1)*nums.size()/2;
        for(int i=0;i<nums.size();i++){
            m -= nums[i];
        }
        return m;
    }
};