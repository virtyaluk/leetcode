class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = size(nums1), n = size(nums2), i = 0, j = 0;
        vector<int> ans;
        
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        
        while (i < m and j < n) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return ans;
    }
    
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> um;
        
        for (const int& num: nums1) {
            um[num]++;
        }
        
        for (const int& num: nums2) {
            if (um.count(num)) {
                ans.push_back(num);
                
                um[num]--;
                
                if (not um[num]) {
                    um.erase(num);
                }
            }
        }
        
        return ans;
    }
};