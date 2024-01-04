class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> um;
        vector<int> ans;
        unordered_set<int> us = {3, 5, 6, 7};
        
        for (const int& num: nums1) {
            um[num] |= 1;
        }
        
        for (const int& num: nums2) {
            um[num] |= 2;
        }
        
        for (const int& num: nums3) {
            um[num] |= 4;
        }
        
        for (auto [num, bit]: um) {
            if (us.count(bit)) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};