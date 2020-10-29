class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> m;
        
        for (const int& num: nums) {
            m[num]++;
        }
        
        for (auto [num, count]: m) {
            if (m.count(num + 1)) {
                ans = max(ans, count + m[num + 1]);
            }
        }
        
        return ans;
    }
};