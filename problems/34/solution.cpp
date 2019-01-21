class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        
        ans.front() = lowerBound(nums, target);
        ans.back() = upperBound(nums, target);
        
        return ans;
    }
    
    int lowerBound(vector<int>& nums, int k) {
        int lo = 0, hi = size(nums) - 1, ans = -1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] == k) {
                ans = mid;
                hi = mid - 1;
            } else if (nums[mid] > k) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
    
    int upperBound(vector<int>& nums, int k) {
        int lo = 0, hi = size(nums) - 1, ans = -1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] == k) {
                ans = mid;
                lo = mid + 1;
            } else if (nums[mid] > k) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};