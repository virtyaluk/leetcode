class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0, num = -1, j = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num) {
                cnt++;
            } else {
                cnt = 1;
                num = nums[i];
            }
            
            if (cnt <= 2) {
                nums[j++] = nums[i];
            }
        }
        
        return j;
    }
};