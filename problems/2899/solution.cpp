class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> ans, seen;
        // deque<int> seen;
        
        for (int i = 0, k = 0; i < size(nums); i++) {
            if (nums[i] > 0) {
                seen.push_back(nums[i]);
                k = 0;
            } else {
                k++;
            }
            
            if (k > 0 and k <= size(seen)) {
                ans.push_back(seen[size(seen) - k]);
            } else if (k > size(seen)) {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};