class Solution {
public:
    bool dfs(vector<int>& sides,vector<int>& matches, int index, int target) {
        if (index == matches.size())
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        for(int i=0;i<4;i++){
            if(sides[i] + matches[index] > target) // 1st. Pruning, sides' length cannot exceed target
                continue;
            // 3rd. Pruning, if checked same length, pass this side
            int j = i;
            while(--j >= 0) {
                if(sides[j] == sides[i]) break;
            }
            if(j!=-1) continue;
            sides[i] += matches[index];
            if (dfs(sides, matches, index + 1, target))
                return true;
            sides[i] -= matches[index];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        if(nums.size() <= 3) return false;
        int sum = 0;
        for(int i: nums){
            sum += i;
        }
        if(sum % 4) return false;
        vector<int> sides(4, 0);
        // 2nd. Pruning, start with the longest matches.
        sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;});
        return dfs(sides, nums, 0, sum / 4);
    }
};