class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> q;
        int ans = 0;
        bool seenZero = false;
        
        for (const int& num: nums) {
            if (not num) {
                q.push_back(0);
                seenZero = true;
            } else {
                if (empty(q) or not q.back()) {
                    q.push_back(1);
                } else {
                    q.back()++;
                }
            }
        }
        
        for (int i = 0, cur = 0; i < size(q); i++) {
            cur += q[i];
            
            if (i >= 3) {
                cur -= q[i - 3];
            }
            
            ans = max(ans, cur);
        }
        
        ans -= !seenZero;
        
        return ans;
    }
};