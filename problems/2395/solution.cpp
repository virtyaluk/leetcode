class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<long long> us;
        long long sum = nums.front();
        
        for (int i = 1; i < size(nums); i++) {
            sum += nums[i];
            
            if (i >= 2) {
                sum -= nums[i - 2];
            }
            
            if (us.count(sum)) {
                return true;
            } else {
                us.insert(sum);
            }
        }
        
        return false;
    }
};