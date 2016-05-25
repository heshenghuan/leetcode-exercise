class Solution {
public:
    int nthUglyNumber(int n) {
        int idx2 = 0, idx3 = 0, idx5 = 0;
        vector<int> uglyNum(n,0);
        uglyNum[0] = 1;
        int count = 1;
        while(count < n) {
            int newUgly = minof(uglyNum[idx2] * 2,uglyNum[idx3] * 3, uglyNum[idx5] * 5);
            uglyNum[count++] = newUgly;
            //切记这里不可用if{}else if{}的嵌套判断
            if (newUgly == uglyNum[idx2] * 2) {
                idx2++;
            }
            if (newUgly == uglyNum[idx3] * 3) {
                idx3++;
            }
            if (newUgly == uglyNum[idx5] * 5) {
                idx5++;
            }
        }
        return uglyNum[n-1];
    }
    int minof(int a, int b, int c){
        int tmp = a<b?a:b;
        return tmp<c?tmp:c;
    }
};