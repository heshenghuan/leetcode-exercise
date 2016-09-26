class Solution {
public:
    /* Calculate a square root of x with Newton's method
     * https://en.wikipedia.org/wiki/Newton%27s_method
     * Assume the square root of x is r, then we have equation "r^2 - x = 0"
     * Let f(r) = r^2 - x, and we know f'(r) = 2r
     * so the update rule is (assume r' is the next iteration value): 
     * r' = r - f(r) / f'(r)
     *    = r - (r^2 - x)/(2r)
     *    = (r + x/r) / 2
     */
    int mySqrt(int x) {
        long long r = x;
        while(r*r > x) {
            r = (r + x/r) / 2;
        }
        return r;
    }
};