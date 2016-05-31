class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        if(strs.size() == 0) 
            return ans;
        sort(strs.begin(), strs.end());
        map<string, vector<string> > hash;
        for(int i=0;i<strs.size();i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            hash[str].push_back(strs[i]);
        }
        
        map<string, vector<string> >::iterator it;
        for(it = hash.begin();it != hash.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};