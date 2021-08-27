class Solution {
private:
    vector<int> ans;
    set<int> s;
    
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) {
            for (int i = 0; i < 10; i++) {
                ans.push_back(i);
            }
            
            return ans;
        }
        
        for (int i = 1; i < 10; i++) {
            dfs(i, N - 1, K);
        }
        
        ans.assign(s.begin(), s.end());
        return ans;
    }
    
    void dfs(int num, int n, int k) {
        if (n == 0) {
            s.insert(num);
            return;
        }
        
        int lastDigit = num % 10;
        
        if (lastDigit + k <= 9) {
            dfs(num * 10 + lastDigit + k, n - 1, k);
        }
        
        if (lastDigit - k >= 0) {
            dfs(num * 10 + lastDigit - k, n - 1, k);
        }
    }
};