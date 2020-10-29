class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long int> balance;
        vector<long int> debt;
        
        for (const vector<int>& trans: transactions) {
            balance[trans[0]] -= trans[2];
            balance[trans[1]] += trans[2];
        }
        
        for (auto [ignore, bal]: balance) {
            if (bal) {
                debt.push_back(bal);
            }
        }
        
        return dfs(debt, 0);
    }
    
    int dfs(vector<long int>& debt, int s) {
        while (s < size(debt) and not debt[s]) {
            s++;
        }
        
        int ans = INT_MAX;
        
        for (int i = s + 1, prev = 0; i < size(debt); i++) {
            if (debt[i] != prev and debt[i] * debt[s] < 0) {
                debt[i] += debt[s];
                ans = min(ans, 1 + dfs(debt, s + 1));
                prev += (debt[i] -= debt[s]);
            }
        }
        
        return ans < INT_MAX ? ans : 0;
    }
};