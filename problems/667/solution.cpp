class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int si = 1, sj = k + 1;
        
        for (int i = 0; i < n; i++) {
            if (sj >= si) {
                if (i % 2 == 0) {
                    ans[i] = si++;
                } else {
                    ans[i] = sj--;
                }
            } else {
                ans[i] = i + 1;
            }
        }
        
        return ans;
    }
    
    vector<int> constructArray1(int n, int k) {
        vector<int> ans(n);
        int start = 1, i = 0, kk = k;
        
        while (i <= kk) {
            ans[i++] = start++;
            
            if (i <= kk) {
                ans[i++] = 1 + k--;
            }
        }
        
        for (; i < n; i++) {
            ans[i] = i + 1;
        }
        
        return ans;
    }
};