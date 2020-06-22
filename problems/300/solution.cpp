class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        
        for (const int& num: nums) {
            auto it = lower_bound(begin(dp), end(dp), num);
            
            if (it == end(dp)) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }
        
        return size(dp);
    }
    
    int lengthOfLIS1(vector<int>& nums) {
        vector<int> dp;
        
        for (const int& num: nums) {
            cout << num << ": " << lowerBound(dp, num) << endl;
            int idx = lowerBound(dp, num);
            
            if (idx >= dp.size()) {
                dp.push_back(num);
            } else {
                dp[idx] = num;
            }
        }
        
        return dp.size();
    }
    
    int lowerBound(const vector<int>& ar, const int& num) {
        int lo = 0, hi = ar.size() - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (ar[mid] < num) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo;
    }
    
    int lengthOfLIS2(vector<int>& nums) {
        int ans = 1;
        vector<int> dp(nums.size(), 1);
        
        for (int i = 1; i < nums.size(); i++) {
            int cur = 0;
            
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    cur = max(cur, dp[j]);
                }
            }
            
            dp[i] = cur + 1;
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};