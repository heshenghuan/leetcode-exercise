class Solution {
public:
    /*
     * 思路就是按照运算符将式子分为左右两部分，然后递归处理
     * 递归到最底层，input只剩一个数，直接返回它即可
     */
    vector<int> diffWaysToCompute(string input) {
        if(input.size() == 0) return vector<int>();
        vector<int> res;
        for(int i=0;i<input.size();i++) {
            if(input[i] != '+' && input[i] != '-' && input[i] != '*')
                continue;
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1));
            for(auto val1 : left) {
                for(auto val2 : right) {
                    if (input[i] == '+') res.push_back(val1 + val2);
                    else if (input[i] == '-') res.push_back(val1 - val2);
                    else if (input[i] == '*') res.push_back(val1 * val2);
                }
            }
        }
        return res.empty()?vector<int> {stoi(input)} : res;
    }
};