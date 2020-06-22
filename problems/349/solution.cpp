class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = size(nums1), m = size(nums2), i = 0, j = 0;
        vector<int> ans;
        
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        
        while (i < n and j < m) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
            
            while (i > 0 and i < n and nums1[i] == nums1[i - 1]) {
                i++;
            }
            
            while (j > 0 and j < m and nums2[j] == nums2[j - 1]) {
                j++;
            }
        }
        
        return ans;
    }
    
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> um(begin(nums1), end(nums1));
        
        for (const int& num: nums2) {
            if (um.count(num)) {
                ans.push_back(num);
                um.erase(num);
            }
        }
        
        return ans;
    }
};