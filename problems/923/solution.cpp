#define ll long long int

const int MOD = 1e9 + 7;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        ll ans = 0;
        unordered_map<ll, ll> freq;
        
        for (const int& num: arr) {
            freq[num]++;
        }
        
        for (auto [i, ignore]: freq) {
            for (auto [j, ignore]: freq) {
                ll k = target - i - j;
                
                if (not freq.count(k)) {
                    continue;
                }
                
                if (i == j and j == k) {
                    ans += freq[i] * (freq[j] - 1) * (freq[k] - 2) / 6;
                } else if (i == j and j != k) {
                    ans += freq[i] * (freq[j] - 1) / 2 * freq[k];
                } else if (i < j and j < k) {
                    ans += freq[i] * freq[j] * freq[k];
                }
            }
        }
        
        return ans % MOD;
    }
};