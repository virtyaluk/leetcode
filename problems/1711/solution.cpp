#define ll long long int
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int n = deliciousness.size();
        ll ans = 0;
        unordered_map<int, int> m;
        
        for (int& num: deliciousness) {
            for (int i = 0; i < 22; i++) {
                ll t = pow(2, i) - num;
                
                if (t < 0) {
                    continue;
                }
                
                if (m.count(t)) {
                    ans += m[t];
                }
                
                ans %= MOD;
            }
            
            m[num]++;
        }
        
        return ans;
    }
};