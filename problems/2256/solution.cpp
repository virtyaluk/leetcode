class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int ans = 0,
            leftCnt = 0,
            rightCnt = size(nums);
        long long int minAvgDif = INT_MAX,
            leftSum = 0,
            rightSum = accumulate(begin(nums), end(nums), 0l),
            curAvg = 0;
        
        for (int i = 0; i < size(nums); i++) {
            leftSum += nums[i];
            rightSum -= nums[i];
            leftCnt++;
            rightCnt--;
            curAvg = abs((leftCnt == 0 ? 0 : leftSum / leftCnt) - (rightCnt == 0 ? 0 : rightSum / rightCnt));
            
            if (curAvg < minAvgDif) {
                ans = i;
                minAvgDif = curAvg;
            }
        }
        
        return ans;
    }
};