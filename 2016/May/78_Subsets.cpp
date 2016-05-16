class Solution {
public:
    /*
    * 递推思想解决问题：
    * 空集的子集是空集，一个元素的集合的所有子集是空集和它本身；
    * 线性扫描nums中的元素，每有一个新元素就将该元素与子集簇中的的各子集的并作为新子集加入到子集簇中。
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> emp;
        ans.push_back(emp);
        sort(nums.begin(), nums.end());
        if (nums.size() == 0) return ans;
        for(vector<int>::iterator ind = nums.begin(); ind < nums.end(); ++ind)
        {
            int size = ans.size();
            for(int i = 0; i < size; ++i)
            {
                vector<int> tmp;
                for(vector<int>::iterator j = ans[i].begin(); j < ans[i].end(); ++j)
                    tmp.push_back(*j);
                tmp.push_back(*ind);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};