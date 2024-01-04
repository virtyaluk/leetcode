class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rightSum = accumulate(begin(nums), end(nums), 0),
            leftSum = 0;
        vector<int> ans;
        
        for (const int& num: nums) {
            rightSum -= num;
            ans.push_back(abs(leftSum - rightSum));
            leftSum += num;
        }
        
        return ans;
    }
};