class Solution {
    vector<vector<string> > ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> curAns(n);
        solution(curAns, n, 0);
        return ans;
    }

private:
    void solution(vector<int> &curAns, int n, int curLine) {
        if (curLine == n) {
            vector<string> ansStr(n, string(n, '.'));
            for(int i = 0; i < n; i++) {
                ansStr[i][curAns[i]] = 'Q';
            }
            ans.push_back(ansStr);
            return;
        }
        
        for(curAns[curLine] = 0; curAns[curLine] < n; curAns[curLine]++)
            if(check(curAns, n, curLine))
                solution(curAns, n, curLine + 1);
    }
    
    bool check(vector<int> &curAns, int n, int curLine) {
        for(int i = 0; i < curLine; i++){
            if(curAns[i] == curAns[curLine] || abs(curAns[curLine] - curAns[i]) == abs(curLine - i))
                return false;
        }
        return true;
    }
};