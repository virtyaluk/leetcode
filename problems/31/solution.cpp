class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = size(nums), hi = n - 2;
        
        while (hi >= 0 and nums[hi] >= nums[hi + 1]) {
            hi--;
        }
        
        if (hi >= 0) {
            int lo = n - 1;
            
            while (nums[hi] >= nums[lo]) {
                lo--;
            }
            
            swap(nums[hi], nums[lo]);
        }
        
        reverse(begin(nums) + hi + 1, end(nums));
    }
    
    void nextPermutation1(vector<int>& nums) {
        // find first unsorted element right to left
        auto dest = is_sorted_until(rbegin(nums), rend(nums));
        
        if (dest != rend(nums)) {
            // find first greater element in range right to dest
            auto target = upper_bound(rbegin(nums), dest, *dest);
            // swap elements
            swap(*dest, *target);
        }
        
        // swap range from right till dest
        reverse(rbegin(nums), dest);
    }
};