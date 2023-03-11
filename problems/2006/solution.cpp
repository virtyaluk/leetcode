class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> um;
        
        for (const int& num: nums) {
            um[num]++;
        }
        
        for (auto &[num, ignore]: um) {
            if (um.count(num + k)) {
                ans += um[num] * um[num + k];
            }
        }
        
        return ans;
    }
};