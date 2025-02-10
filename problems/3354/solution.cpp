class Solution {
private:
    bool isValid(vector<int> nums, int cur, int dir) {
        while (cur >= 0 and cur < size(nums)) {
            if (nums[cur] == 0) {
                cur += dir == 0 ? -1 : 1;
            } else {
                nums[cur]--;
                dir = dir == 0 ? 1 : 0;
                cur += dir == 0 ? -1 : 1;
            }
        }
        
        return accumulate(begin(nums), end(nums), 0) == 0;
    }
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] != 0) {
                continue;
            }
            
            ans += isValid(nums, i, 0);
            ans += isValid(nums, i, 1);
        }
        
        return ans;
    }
};