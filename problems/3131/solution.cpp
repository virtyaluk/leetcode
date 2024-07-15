class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        
        return nums2.front() - nums1.front();
    }
};