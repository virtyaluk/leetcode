class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elSum = 0,
            digitSum = 0;
        
        for (int num: nums) {
            elSum += num;
            
            while (num) {
                digitSum += num % 10;
                num /= 10;
            }
        }
        
        return abs(elSum - digitSum);
    }
};