class Solution {
public:
    int myPow(int a, int n) {
        int ans = 1;
        a %= 1337;
        for(int i=0;i<n;i++) ans = (ans * a) % 1337;
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int lastdigit = b.back();
        b.pop_back();
        return myPow(superPow(a, b),10) * myPow(a,lastdigit) % 1337;
    }
};