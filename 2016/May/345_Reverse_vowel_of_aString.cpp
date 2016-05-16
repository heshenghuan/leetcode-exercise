class Solution {
public:
    string vowel = "aAeEiIoOuU";
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            while(left < right && !is_vowel(s[left])) left++;
            while(left < right && !is_vowel(s[right])) right--;
            
            if(left >= right) break;
            
            // swap the left and right
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
        return s;
    }
    bool is_vowel(char a) {
        int l = vowel.length();
        for(int i=0;i<l;i++){
            if(a == vowel[i]) return true;
        }
        return false;
    }
};