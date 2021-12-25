typedef long long int ll;

const ll MOD = 1e9 + 7;
const ll base = 1e5 + 1;

class Solution {
public:
    bool rollingHash(string& s, const vector<ll>& powers, int len) {
        ll hash = 0;
        unordered_set<ll> seen;
        
        for (int i = 0; i < len; i++) {
            hash = (hash + (s[i] * powers[len - i]) % MOD) % MOD;
        }
        
        seen.insert(hash);
        
        for (int i = len; i < size(s); i++) {
            hash = (hash - (s[i - len] * powers[len]) % MOD + MOD) % MOD;
            hash = (hash * base) % MOD;
            hash = (hash + (s[i] * base) % MOD) % MOD;
            
            if (seen.count(hash)) {
                return true;
            }
            
            seen.insert(hash);
        }
        
        return false;
    }
    
    int longestRepeatingSubstring(string s) {
        int n = size(s), lo = 1, hi = n;
        vector<ll> powers = {1};
        
        for (int i = 0; i < n; i++) {
            powers.push_back(powers.back() * base % MOD);
        }
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (rollingHash(s, powers, mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return lo - 1;
    }
};