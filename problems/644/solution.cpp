class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double minVal = *min_element(nums.begin(), nums.end()),
            maxVal = *max_element(nums.begin(), nums.end());
        double prevMid = maxVal, error = INT_MAX;
        
        while (error > 0.00001) {
            double mid = (maxVal + minVal) * 0.5;
            
            if (check(nums, mid, k)) {
                minVal = mid;
            } else {
                maxVal = mid;
            }
            
            error = abs(prevMid - mid);
            prevMid = mid;
        }
        
        return minVal;
    }
    
    bool check(vector<int>& nums, double mid, int k) {
        double sum = 0, prev = 0, minSum = 0;
        
        for (int i = 0; i < k; i++) {
            sum += nums[i] - mid;
        }
        
        if (sum >= 0) {
            return true;
        }
        
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - mid;
            prev += nums[i - k] - mid;
            minSum = min(minSum, prev);
            
            if (sum >= minSum) {
                return true;
            }
        }
        
        return false;
    }
};