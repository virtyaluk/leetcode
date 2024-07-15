class Solution {
private:
    bool check(unordered_map<char, int>& um) {
        for (auto [_, cnt]: um) {
            if (cnt > 2) {
                return false;
            }
        }
        
        return true;
    }
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> um;
        
        for (int lo = 0, hi = 0; hi < size(s); hi++) {
            um[s[hi]]++;
            
            while (not check(um)) {
                um[s[lo++]]--;
            }
            
            ans = max(ans, hi - lo + 1);
        }
        
        return ans;
    }
};