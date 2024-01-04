class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if (size(nums) == 1) {
            return nums.front();
        }
        
        while (size(nums) != 1) {
            vector<int> ar;
            bool flag = true;
            
            for (int i = 0; i < size(nums); i += 2) {
                if (flag) {
                    ar.push_back(min(nums[i], nums[i + 1]));
                } else {
                    ar.push_back(max(nums[i], nums[i + 1]));
                }
                
                flag = !flag;
            }
            
            nums = ar;
        }
        
        return nums.front();
    }
};