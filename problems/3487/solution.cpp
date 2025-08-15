class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxEl = INT_MIN,
            ans = 0;
        unordered_set<int> us;
        
        for (const int& num: nums) {
            maxEl = max(maxEl, num);
            
            if (num > 0 and not us.count(num)) {
                ans += num;
                us.insert(num);
            }
        }

        if (maxEl < 0) {
            return maxEl;
        }

        return ans;
    }
};