class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        
        for (int i = 1; i < size(nums); i++) {
            cnt += nums[i - 1] > nums[i];
        }
        
        cnt += nums.back() > nums.front();
        
        return cnt <= 1;
    }
};