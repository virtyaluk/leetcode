class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2);
        unordered_set<int> us1(begin(nums1), end(nums1)),
            us2(begin(nums2), end(nums2));
        
        for (const int& num: nums1) {
            ans[0] += us2.count(num);
        }
        
        for (const int& num: nums2) {
            ans[1] += us1.count(num);
        }
        
        return ans;
    }
};