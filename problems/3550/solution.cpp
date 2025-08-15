class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < size(nums); i++) {
            int num = nums[i],
                sum = 0;
            
            while (num) {
                sum += num % 10;
                num /= 10;
            }

            if (sum == i) {
                return i;
            }
        }

        return -1;
    }
};