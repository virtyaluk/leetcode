class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int take = 0, skip = 0, prev = -1;
        vector<int> count(pow(10, 4) + 1);
        
        for (const int& num: nums) {
            count[num]++;
        }
        
        for (int i = 0; i < count.size(); i++) {
            if (count[i] > 0) {
                int m = max(take, skip);
                
                if (prev != i - 1) {
                    take = i * count[i] + m;
                    skip = m;
                } else {
                    take = i * count[i] + skip;
                    skip = m;
                }
            
                prev = i;
            }
        }
        
        return max(take, skip);
    }
    
    // [0, 0, 1, 1, 1, 0, 0]
    
    int ans = 0;
    int deleteAndEarn1(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for (const int& num: nums) {
            m[num]++;
        }
        
        for (auto [num, ignore]: m) {
            dfs(m, num, 0);
        }
        
        return ans;
    }
    
    void dfs(unordered_map<int, int> m, int num, int earn) {
        earn += num * m[num];
        
        m.erase(num);
        
        if (m.count(num + 1)) {
            m.erase(num + 1);
        }
        
        if (m.count(num - 1)) {
            m.erase(num - 1);
        }
        
        if (m.empty()) {
            ans = max(ans, earn);
            return;
        }
        
        for (auto [next, ignore]: m) {
            dfs(m, next, earn);
        }
    }
};