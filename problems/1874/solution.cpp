class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2), greater());
        
        for (int i = 0; i < size(nums1); i++) {
            ans += nums1[i] * nums2[i];
        }
        
        return ans;
    }
};