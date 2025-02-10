class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        
        sort(begin(nums), end(nums));
        
        for (int i = 0; i < size(nums); i++) {
            auto it1 = lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]),
                it2 = lower_bound(begin(nums) + i + 1, end(nums), upper - nums[i] + 1);
            
            ans += 1ll * distance(it1, it2);
        }
        
        return ans;
    }
};