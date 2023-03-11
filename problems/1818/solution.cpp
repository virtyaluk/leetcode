typedef long long int ll;

const int MOD = 1000000007;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        ll ans = 0, dif = 0;
        set<int> s(begin(nums1), end(nums1));
        
        for (int i = 0; i < nums1.size(); i++) {
            ll cur = abs((ll) nums1[i] - (ll) nums2[i]);
            ans += cur;
            
            if (dif < cur) {
                auto it = lower_bound(begin(s), end(s), nums2[i]);
                
                if (it != end(s)) {
                    dif = max(dif, cur - abs(*it - (ll) nums2[i]));
                }
                
                if (it != begin(s)) {
                    dif = max(dif, cur - abs(*prev(it) - (ll) nums2[i]));
                }
            }
        }
        
        return (ans - dif) % MOD;
    }
};