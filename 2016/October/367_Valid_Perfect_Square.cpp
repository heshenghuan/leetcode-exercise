class Solution {
public:
    int mySqrt(int x) {
        long long r = x;
        while(r*r > x) {
            r = (r + x/r) / 2;
        }
        return r;
    }
    bool isPerfectSquare(int num) {
       int sq = mySqrt(num);
       return sq*sq == num;
    }
};