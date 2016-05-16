class Solution {
public:
    string reverseString(string s) {
        string ans;  
        int length = s.length();  
        for(int i = length-1;i>=0;i--)
            ans+=s[i];  
        return ans;  
    }
};