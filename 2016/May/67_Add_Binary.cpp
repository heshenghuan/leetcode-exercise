class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length();
        int blen = b.length();
        
        // if one is empty, just return the other
        if(alen == 0)
            return b;
        else if(blen == 0)
            return a;
        
        // carry bit
        int carry = 0;
        // return value
        string r = alen > blen ? a : b ;
        int k = alen > blen ? alen - 1 : blen - 1;
        int ia = alen - 1, ib = blen - 1;
        // stimulation of adding two binary nums
        for(;ia>=0&&ib>=0;ia--, ib--)
        {
            int tmp = (a[ia] - '0') + (b[ib] - '0') + carry;
            if(tmp>=2)
            {
                tmp -= 2;
                carry = 1;
            }
            else
                carry = 0;
            r[k--] = tmp + '0';
        }
        while(ia >= 0)
        {
            int tmp = (a[ia--] - '0') + carry;
            if (tmp >= 2)
            {
                tmp -= 2;
                carry = 1;
            }
            else
                carry = 0;
            r[k--] = tmp + '0';
        }
        while(ib >= 0)
        {
            int tmp = (b[ib--] - '0') + carry;
            if (tmp >= 2)
            {
                tmp -= 2;
                carry = 1;
            }
            else
                carry = 0;
            r[k--] = tmp + '0';
        }
        // carry bit still not zero, insert 1 to the head
        if(carry)
            return "1"+r;
        else
            return r;
    }
};