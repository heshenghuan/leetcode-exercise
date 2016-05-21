class Solution {
public:
    bool isValid(string s) {
        stack<char> bs;
        for(int i=0;i<s.size();i++) { 
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                bs.push(s[i]);
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']') {
                bool flag = true;
                switch (s[i]) {
                    case ')': if(!bs.empty() && bs.top() == '(') bs.pop(); else flag = false; break;
                    case '}': if(!bs.empty() && bs.top() == '{') bs.pop(); else flag = false; break;
                    case ']': if(!bs.empty() && bs.top() == '[') bs.pop(); else flag = false; break;
                    default: break;
                }
                if (!flag) return false;
            }
            else continue;
        }
        if(!bs.empty()) return false;
        return true;
    }
};