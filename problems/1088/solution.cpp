class Solution {
private:
    unordered_map<int, int> um = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
    void backtrack(long factor, long original, long rotated, long n, int& ans) {
        if (original > n) {
            return;
        }
        
        ans += rotated != original;
        
        for (auto it = begin(um);  it != end(um); it++) {
            if (factor > 1 and original == 0) {
                continue;
            }
            
            backtrack(factor * 10, original * 10 + it->first, it->second * factor + rotated, n, ans);
        }
    }
public:
    int confusingNumberII(int n) {
        int ans = 0;
        
        backtrack(1, 0, 0, n, ans);
        
        return ans;
    }
};