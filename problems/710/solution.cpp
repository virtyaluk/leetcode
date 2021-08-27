class Solution {
private:
    int wLen;
    unordered_map<int, int> um;

public:
    Solution(int n, vector<int>& blacklist) {
        unordered_set<int> us;
        wLen = n - size(blacklist);
        
        for (int i = wLen; i < n; i++) {
            us.insert(i);
        }
        
        for (const int& x: blacklist) {
            us.erase(x);
        }
        
        auto it = begin(us);
        
        for (const int& x: blacklist) {
            if (x < wLen) {
                um[x] = *it++;
            }
        }
    }
    
    int pick() {
        int k = rand() % wLen;
        
        return um.count(k) ? um[k] : k;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */