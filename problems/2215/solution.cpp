class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us1{begin(nums1), end(nums1)},
            us2{begin(nums2), end(nums2)};
        vector<int> n1, n2;
        
        for (const int& num: nums1) {
            if (not us2.count(num)) {
                n1.push_back(num);
                us2.insert(num);
            }
        }
        
        for (const int& num: nums2) {
            if (not us1.count(num)) {
                n2.push_back(num);
                us1.insert(num);
            }
        }
        
        return {n1, n2};
    }
};