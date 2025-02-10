class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int ans = 0,
            cur = 0;
        map<int, int> m;
        
        for (const vector<int>& in: intervals) {
            m[in.front()]++;
            m[in.back() + 1]--;
        }
        
        for (auto [_, inc]: m) {
            cur += inc;
            ans = max(ans, cur);
        }
        
        return ans;
    }
};