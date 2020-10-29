class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int m = INT_MAX, M = INT_MIN, left = 0, right = nums.size() - 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                m = min(m, nums[i]);
            }
        }
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                M = max(M, nums[i]);
            }
        }
        
        for (; left < nums.size(); left++) {
            if (nums[left] > m) {
                break;
            }
        }
        
        for (; right >= 0; right--) {
            if (nums[right] < M) {
                break;
            }
        }
        
        return left > right ? 0 : right - left + 1;
    }
    
    int findUnsortedSubarray2(vector<int>& nums) {
        int ans = nums.size();
        vector<int> nums2(begin(nums), end(nums));
        
        sort(begin(nums2), end(nums2));
        
        for (int i = 0; i < nums.size() and ans > 0; i++) {
            if (nums[i] == nums2[i]) {
                ans--;
            } else {
                break;
            }
        }
        
        for (int i = nums.size() - 1; i >= 0 and ans > 0; i--) {
            if (nums[i] == nums2[i]) {
                ans--;
            } else {
                break;
            }
        }
        
        return ans;
    }
};