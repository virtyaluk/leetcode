class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long ans = 1,
            m = 0;
        
        for (const long long d: damage) {
            ans += d;
            m = max(m, d);
        }
        
        return ans - min(m, (long long) armor);
    }
};