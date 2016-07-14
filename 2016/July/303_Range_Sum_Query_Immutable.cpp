class NumArray {
    map<int, int> sum_of_indice;
public:
    NumArray(vector<int> &nums) {
        sum_of_indice[-1] = 0;
        int sum = 0;
        for(int i=0;i<nums.size();++i) {
            sum += nums[i];
            sum_of_indice[i] = sum;
        }
    }

    int sumRange(int i, int j) {
        return sum_of_indice[j] - sum_of_indice[i-1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);