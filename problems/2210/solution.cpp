class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        vector<int> nums2;
        
        for (const int& num: nums) {
            if (not empty(nums2) and nums2.back() == num) {
                continue;
            }
            
            nums2.push_back(num);
        }
        
        for (int i = 1; i < size(nums2) - 1; i++) {
            ans += (nums2[i - 1] > nums2[i] and nums2[i + 1] > nums2[i]) or (nums2[i - 1] < nums2[i] and nums2[i + 1] < nums2[i]);
        }
        
        return ans;
    }
};