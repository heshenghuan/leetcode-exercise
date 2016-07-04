class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0) return false;
        if(num&(num - 1)) return false; //先判断是否为2的幂
        if(num&0x55555555) return true; //再将其中不是4的幂的去掉
        return false;
    }
};