class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(size(l));
        
        for (int i = 0; i < size(l); i++) {
            int left = l[i],
                right = r[i],
                len = right - left + 1,
                m = INT_MAX,
                M = INT_MIN;
            
            if (right - left + 1 < 2) {
                continue;
            }
            
            for (int k = left; k <= right; k++) {
                m = min(m, nums[k]);
                M = max(M, nums[k]);
            }
            
            if (m == M) {
                ans[i] = true;
            } else if ((M - m) % (len - 1)) {
                ans[i] = false;
            } else {
                int dif = (M - m) / (len - 1);
                vector<bool> subar(len);
                
                for (; left <= right; left++) {
                    if ((nums[left] - m) % dif or subar[(nums[left] - m) / dif]) {
                        break;
                    }
                    
                    subar[(nums[left] - m) / dif] = true;
                }
                
                ans[i] = left > right;
            }
        }
        
        return ans;
    }
};