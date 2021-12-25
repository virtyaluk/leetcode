class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int lo = 0, hi = size(nums);
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] - mid - k >= nums[0]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return nums[0] + lo + k - 1;
    }
    
    int missingElement2(vector<int>& nums, int k) {
        int lo = 0, hi = size(nums) - 1, missing = 0;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            missing = nums[mid] - nums[0] - mid;
            
            if (k > missing) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        // cout << lo << ", " << hi << ", " << missing << endl;
        
        if (missing >= k) {
            return nums[lo] - 1 - (missing - k);
        }
        
        return nums[hi] + (k - missing);
    }
    
    int missingElement1(vector<int>& nums, int k) {
        int n = size(nums);
        
        for (int i = 1; i < n; i++) {
            int dif = nums[i] - nums[i - 1] - 1;
            
            if (dif >= k) {
                return nums[i - 1] + k;
            }
            
            k -= dif;
        }
        
        return nums.back() + k;
    }
};