class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        
        for (int i = 0, j = -1; i < size(nums1); i++) {
            while (j + 1 < size(nums2) and nums1[i] <= nums2[j + 1]) {
                j++;
            }
            
            ans = max(ans, j - i);
        }
        
        return ans;
    }
};