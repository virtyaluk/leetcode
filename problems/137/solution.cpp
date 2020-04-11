class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int oneTime = 0, threeTimes = 0;
        
        for (const int& num: nums) {
            oneTime = ~threeTimes & (oneTime ^ num);
            threeTimes = ~oneTime & (threeTimes ^ num);
        }
        
        return oneTime;
    }
};