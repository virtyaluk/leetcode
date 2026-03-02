class Solution {
private:
    long long get(int num) {
        int i = 1,
            base = 1;
        long long ans = 0;
        
        while (base <= num) {
            ans += 1ll * (i + 1) / 2 * (min(base * 2 - 1, num) - base + 1);
            i++;
            base *= 2;
        }
        
        return ans;
    }

public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        
        for (const vector<int>& q: queries) {
            ans += (get(q.back()) - get(q.front() - 1) + 1) / 2;
        }
        
        return ans;
    }
};