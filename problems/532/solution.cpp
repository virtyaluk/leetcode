class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> m;
        
        for (int num: nums) {
            m[num]++;
        }
        
        for (auto [key, val]: m) {
            if (k > 0 && m.find(key + k) != m.end()) {
                ans++;
            } else if (k == 0 && val > 1) {
                ans++;
            }
        }
        
        return ans;
    }
};