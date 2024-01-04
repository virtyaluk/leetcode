class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, vector<int>> um;
        
        for (int i = 0; i < size(nums); i++) {
            for (const int& j: um[nums[i]]) {
                ans += (i * j) % k == 0;
            }
            
            um[nums[i]].push_back(i);
        }
        
        return ans;
    }
};