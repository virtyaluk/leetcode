class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, cur = 0, left = 0, right = 0;
        unordered_set<int> us;
        
        while (left < nums.size() and right < nums.size()) {
            if (not us.count(nums[right])) {
                cur += nums[right];
                us.insert(nums[right++]);
                ans = max(ans, cur);
            } else {
                cur -= nums[left];
                us.erase(nums[left++]);
            }
        }
        
        return ans;
    }
};