class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us(begin(nums1), end(nums1));
        
        for (const int& num: nums2) {
            if (us.count(num)) {
                return num;
            }
        }
        
        return -1;
    }
};