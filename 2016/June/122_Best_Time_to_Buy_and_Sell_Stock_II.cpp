class Solution {
public:
    /*
    * 考虑这个问题，如何多次交易获利最多？有钱就赚啊！能交易就交易。
    * 所以只要交易价格高于买入价格就卖（且完成尽可能多次），于是就有了下面的算法。
    */
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int profit = 0;
        for(int i=1;i<prices.size();++i) {
            profit += max(0, prices[i] - prices[i-1]);
        }
        return profit;
    }
};