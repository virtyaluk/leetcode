class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        slow = nums[0];
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
    
    int findDuplicate1(vector<int>& nums) {
        int lo = 1, hi = size(nums) - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2,
                less = 0;
            
            for (const int& num: nums) {
                if (num <= mid) {
                    less++;
                }
            }
            
            if (less > mid) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};