class Solution {
private:
    int check(const unordered_map<char, int>& um) {
        int m = INT_MAX, M = 0;
        
        for (auto [_, freq]: um) {
            m = min(m, freq);
            M = max(M, freq);
        }
        
        return M - m;
    }
public:
    int beautySum(string s) {
        int ans = 0;
        
        for (int i = 0; i < size(s); i++) {
            unordered_map<char, int> um;
            
            for (int j = i; j < size(s); j++) {
                um[s[j]]++;
                
                ans += check(um);
            }
        }
        
        return ans;
    }
};