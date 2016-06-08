class Solution {
public:
    /*
     * 注意题目中说任意两个字符不会映射到同一个字符，但有可能映射到自身
     * 简单来说，就是对于任意一个字符有映射： x => (x or y) y != x
     * 需要两张表来维持映射关系，从s到t是一一映射，从t到s也是。
     */
    // 8ms 直接用vector当做hash表，也即hash函数h(x) = x
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> map1(127, 0);
        vector<int> map2(127, 0);
        for(int i=0;i<s.size();i++) {
            char schar = s[i];
            char tchar = t[i];
            if (map1[schar] == 0 && map2[tchar] == 0) {
                map1[schar] = tchar;
                map2[tchar] = schar;
            }
            else if (map1[schar] != tchar || map2[tchar] != schar){
                return false;
            }
        }
        return true;
    }
    
    // 132ms 使用map太消耗时间
    // bool isIsomorphic(string s, string t) {
    //     if (s.size() != t.size())
    //         return false;
    //     map<char, char> map1;
    //     map<char, char> map2;
    //     for(int i=0;i<s.size();i++) {
    //         char schar = s[i];
    //         char tchar = t[i];
    //         // 连续两个判断保证映射 schar <==> tchar
    //         if(map1.find(schar) != map1.end() && map1[schar] != tchar)
    //             return false;
    //         if(map2.find(tchar) != map2.end() && map2[tchar] != schar)
    //             return false;
    //         // 更新映射关系
    //         map1[schar] = tchar;
    //         map2[tchar] = schar;
    //     }
    //     return true;
    // }
};