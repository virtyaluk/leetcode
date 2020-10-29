class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0, cur = 0; i < size(nums); i++) {
            cur = nums[i] == 0 ? 0 : cur + nums[i];
            ans = max(ans, cur);
}
        
        return ans;
    }
};