class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        for(int i=1;i<=numRows;i++) {
            vector<int> column;
            for(int j=0;j<i;j++) { 
                if(j==0||j==(i-1))
                    column.push_back(1);
                else
                    column.push_back(ans[i-2][j-1] + ans[i-2][j]);
            }
            ans.push_back(column);
        }
        return ans;
    }
};