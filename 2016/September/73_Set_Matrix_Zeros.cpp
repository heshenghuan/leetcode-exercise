class Solution {
public:
    /*
    * Store states of each row in the first of that row, and store states of each
    * column in the first of that column.
    * And use 'col_is_zero' to store if the first col has a zero.
    */
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col_is_zero = 0;
        for(int i=0;i<m;i++) {
            if(matrix[i][0] == 0) col_is_zero = 1;
            for(int j=1;j<n;j++)
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }
        
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=1;j--)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if(col_is_zero) matrix[i][0] = 0;
        }
    }
};