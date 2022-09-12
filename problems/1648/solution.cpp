const int MOD = 1e9 + 7;

class Solution {
public:
    int maxProfit(vector<int>& arr, int orders) {
        long long int ans = 0, colors = 1;
        
        sort(begin(arr), end(arr));
        
        for (int i = size(arr) - 1; i >= 0 and orders > 0; i--, colors++) {
            long long int cur = arr[i],
                prev = i > 0 ? arr[i - 1] : 0,
                rounds = min(orders / colors, cur - prev);
            
            orders -= rounds * colors;
            ans = (ans + (cur * (cur + 1) - (cur - rounds) * (cur - rounds + 1)) / 2 * colors) % MOD;
            
            if (cur - prev > rounds) {
                ans = (ans  + orders * (cur - rounds)) % MOD;
                break;
            }
        }
        
        return ans;
    }
};