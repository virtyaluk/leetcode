class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> m, left, right;
        int maxDegree = 0, ans = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            
            maxDegree = max(maxDegree, m[nums[i]]);
            
            if (left.find(nums[i]) == left.end()) {
                left[nums[i]] = i;
            }
            
            right[nums[i]] = i;
        }
        
        for (auto [num, freq]: m) {
            if (freq == maxDegree) {
                ans = min(ans, right[num] - left[num] + 1);
            }
        }
        
        return ans;
    }
};