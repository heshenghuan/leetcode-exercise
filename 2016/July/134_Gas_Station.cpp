class Solution {
public:
    /*
     * total用来判断是否有解，当total >= 0说明肯定有解，否则无解
     * sum用来判断当前start station，即j的可行性，初始是默认j=0
     * 当发现sum < 0时，sum清零，j = i，表示从这里的下一个station作为开始
     * 因为最后要形成一个环路，所以当某一段sum < 0时，即表示此前所有的站作为起点都是不合适的 
     */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, total = 0;
        int i, j = -1;
        for(i = 0;i < gas.size();++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(sum < 0) {
                sum = 0;
                j = i;
            }
        }
        return total >= 0 ? j + 1 : -1;
    }
};