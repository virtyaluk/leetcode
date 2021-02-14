class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size();
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (target > nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return -1;
    }
};