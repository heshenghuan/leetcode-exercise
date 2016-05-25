class Solution {
public:
    /*
    * 注意到买卖要求买入时间i小于卖出时间j，因此令curMin保存当前最小，profit表示收益
    * curMin取0~i时刻的最小价格，profit表示0~i的最大收益
    * profit的更新只考虑prices[i]-curMin和profit的大小关系，只需要扫描数组，向后考虑即可
    */
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if (m < 1)
            return 0;
        int curMin = prices[0];
        int profit;
        for(int i=0;i<prices.size();i++) {
            curMin = min(curMin, prices[i]);
            profit = max(profit, prices[i]-curMin);
        }
        return profit;
    }
};