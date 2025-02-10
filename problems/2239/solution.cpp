class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int dist = INT_MAX,
            ans = 0;
        
        sort(begin(nums), end(nums));
        
        for (const int& num: nums) {
            if (abs(num) <= dist) {
                dist = abs(num);
                ans = num;
            }
        }
        
        return ans;
    }
};