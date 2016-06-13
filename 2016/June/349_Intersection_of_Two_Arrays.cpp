class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0||nums2.size()==0)
            return vector<int> ();
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(int i=0;i<nums1.size();i++) {
            s1.insert(nums1[i]);
        }
        vector<int> result;
        for(int i=0;i<nums2.size();i++) {
            if (s1.find(nums2[i]) != s1.end())
                s2.insert(nums2[i]);
        }
        for(auto it=s2.begin();it!=s2.end();++it) {
            result.push_back(*it);
        }
        return result;
    }
};