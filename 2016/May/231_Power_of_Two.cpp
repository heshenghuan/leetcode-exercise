class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if n is power of two, n == (10000....000)b
        // so n - 1 = (01111....111)b, and n&(n-1) == 0
        return (n > 0) && (!(n&(n-1)));
    }
};