class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto lo = lower_bound(begin(nums), end(nums), target);
        auto hi = upper_bound(begin(nums), end(nums), target);
        
        return hi - lo > size(nums) / 2;
    }
};