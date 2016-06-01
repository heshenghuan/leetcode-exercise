class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // 初始化，每个孩子至少有一颗糖
        vector<int> candies(n, 1);
        // 由左向右扫描，保证每个higher rating的孩子比其左边的要多一个
        for(int i=1;i<n;i++) {
            if(ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        // 由右向左扫描，保证每个higher rating的孩子比其右边的要多一个
        for(int i=n-2;i>=0;i--) {
            if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
                candies[i] = candies[i+1] + 1;
        }
        int result = 0;
        // 计算总共需要的糖的数目
        for(int i=0;i<n;i++)
            result += candies[i];
            
        return result;
    }
};