class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        if (coins.back() == -1) {
            return {};
        }
        
        int n = size(coins);
        vector<int> ans, sum(n), next(n);
        deque<int> q = {n - 1};
        
        sum.back() = coins.back();
        
        for (int i = n - 2; i >= 0; i--) {
            if (coins[i] == -1) {
                continue;
            }
            
            while (not empty(q) and q.back() > i + maxJump) {
                q.pop_back();
            }
            
            if (empty(q)) {
                return ans;
            }
            
            next[i] = q.back();
            sum[i] = coins[i] + sum[next[i]];
            
            while (not empty(q) and sum[i] <= sum[q.front()]) {
                q.pop_front();
            }
            
            q.push_front(i);
        }
        
        for (int i = 0; i != n - 1; i = next[i]) {
            ans.push_back(i + 1);
        }
        
        ans.push_back(n);
        
        return ans;
    }
    
    vector<int> cheapestJump1(vector<int>& coins, int maxJump) {
        int n = size(coins);
        vector<int> ans, sum(n, INT_MAX), next(n, -1);
        
        if (coins.back() == -1) {
            return ans;
        }
        
        sum.back() = coins.back();
        
        for (int i = n - 2; i >= 0; i--) {
            if (coins[i] == -1) {
                continue;
            }
            
            for (int j = i; j <= min(i + maxJump, n - 1); j++) {
                if (sum[j] < INT_MAX and sum[j] + coins[i] < sum[i]) {
                    sum[i] = sum[j] + coins[i];
                    next[i] = j;
                }
            }
        }

        if (sum.front() == INT_MAX) {
            return ans;
        }
        
        for (int i = 0; i != -1;) {
            ans.push_back(i + 1);
            i = next[i];
        }
        
        return ans;
    }
};