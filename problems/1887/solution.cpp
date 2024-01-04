class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0;
        
        sort(begin(nums), end(nums));
        
        for (int i = 1, els = 0; i < size(nums); i++) {
            if (nums[i] != nums[i - 1]) {
                els++;
            }
            
            ans += els;
        }
        
        return ans;
    }
};