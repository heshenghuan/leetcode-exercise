class Solution {
public:
    bool isOp(string op){
        return op == "+" || op == "-" || op == "*" || op == "/";
    }
    void calc(string op, stack<int> & st) {
        int num1 , num2;
        num1 = st.top() ; st.pop();
        num2 = st.top() ; st.pop();
        if(op == "+") {
            st.push(num2 + num1);
            return;
        }
        else if(op == "-") {
            st.push(num2 - num1);
            return;
        }
        else if(op == "*") {
            st.push(num2 * num1);
            return;
        }
        else {
            st.push(num2 / num1);
            return;
        }
    }
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        if(len == 0) return 0;
        stack<int> nums;
        int ans, a, b;
        for(int i=0;i<len;i++) {
            if(isOp(tokens[i])) {
                calc(tokens[i], nums);
            }
            else {
                nums.push(atoi(tokens[i].c_str()));
            }
        }
        return nums.top();
    }
};