class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 1) return nums[0];
        priority_queue<int> q;
        for (int val:nums) {
            q.push(val);
        }
        
        while(q.size() > len-k+1) {
            q.pop();
        }
        return q.top();
    }
};

// partition, QuickSelect的思想(similar to the quicksort)
// but Memory Limit Exceeded
/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int length = nums.size();
        if(length == 1) return nums[0];
        
        vector<int> left;
        vector<int> right;
        
        for(int i=1;i<length;i++) {
            if(nums[i] > nums[0]) {
                right.push_back(nums[i]);
            }
            else {
                left.push_back(nums[i]);
            }
        }
        length = right.size();
        if(length >= k) {
            return findKthLargest(right, k);
        }
        else if (length == k-1) {
            return nums[0];
        }
        else {
            return findKthLargest(left, k-length-1);
        }
    }
};
*/