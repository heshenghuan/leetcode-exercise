class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        vector<int> tmp;
        ans.push_back(1);
        if(rowIndex <= 0) {
            return ans;
        }
        for(int i=1;i<=rowIndex;i++) {
            tmp = ans;
            ans.clear();
            ans.push_back(1);
            for (int i=0;i<tmp.size()-1;i++) {
                ans.push_back(tmp[i]+tmp[i+1]);
            }
            ans.push_back(1);
        }
        return ans;
    }
};