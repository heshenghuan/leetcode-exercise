class Solution {
public:
    int calculate(string s) {
        stack<int> ops, nums;
        int num = 0, sign = 1, ans = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num  = num * 10 + c - '0';
            }
            else {
                ans += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(ans);
                    ops.push(sign);
                    ans = 0; sign = 1;
                }
                if (c == ')') {
                    ans = nums.top() + ops.top() * ans;
                    ops.pop(); nums.pop();
                }
            }
        }
        ans += sign*num;
        return ans;
    }
};
