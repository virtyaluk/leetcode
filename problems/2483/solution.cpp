class Solution {
public:
    int bestClosingTime(string customers) {
        int n = size(customers);
        vector<int> pref(n + 1, 0),
            suf(n + 1, 0),
            ans(n + 1);
        
        for (int i = 1; i <= n; i++) {
            pref[i] += pref[i - 1];
            pref[i] += customers[i - 1] == 'N';
        }
        
        for (int i = n - 1; i >= 0; i--) {
            suf[i] += suf[i + 1];
            suf[i] += customers[i] == 'Y';
        }
        
        for (int i = 0; i <= n; i++) {
            ans[i] = pref[i] + suf[i];
        }
        
        int minPenalty = *min_element(begin(ans), end(ans));
        
        for (int i = 0; i <= n; i++) {
            if (ans[i] == minPenalty) {
                return i;
            }
        }
        
        return -1;
    }
};