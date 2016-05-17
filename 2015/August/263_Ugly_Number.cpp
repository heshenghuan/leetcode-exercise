class Solution {
public:
    /*
    * 不停地除以2, 3, 5即可，如果是ugly number则最后只剩1了
    */
    bool isUgly(int num) {
        if(num<=0){
            return false;
        }
        while(num%2==0){
            num/=2;
        }
        while(num%3==0){
            num/=3;
        }
        while(num%5==0){
            num/=5;
        }
        return (num==1);
    }
};