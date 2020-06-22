class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = size(nums1), m = size(nums2);
        vector<int> ans(k);
        
        for (int i = max(0, k - m); i <= k and i <= n; i++) {
            vector<int> candidate = merge(maxArray(nums1, i), maxArray(nums2, k - i), k);
            
            if (greater(candidate, 0, ans, 0)) {
                ans = candidate;
            }
        }
        
        return ans;
    }
    
    vector<int> merge(vector<int> nums1, vector<int> nums2, int k) {
        vector<int> ans(k);
        
        for (int i = 0, j = 0, l = 0; l < k; l++) {
            ans[l] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        
        return ans;
    }
    
    bool greater(vector<int> nums1, int i, vector<int> nums2, int j) {
        while (i < size(nums1) and j < size(nums2) and nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        
        return j == size(nums2) or (i < size(nums1) and nums1[i] > nums2[j]);
    }
    
    vector<int> maxArray(vector<int>& nums, int k) {
        int n = size(nums);
        vector<int> ans(k);
        
        for (int i = 0, j = 0; i < n; i++) {
            while (n - i + j > k and j > 0 and ans[j - 1] < nums[i]) {
                j--;
            }
            
            if (j < k) {
                ans[j++] = nums[i];
            }
        }
        
        return ans;
    }
};