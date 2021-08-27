class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int ans = 0, dot = 0, MOD = 1e9 + 7;
        stack<pair<int, int>> st;
        
        for (int i = 0; i < A.size(); i++) {
            int count = 1;
            
            while (!st.empty() && st.top().first >= A[i]) {
                count += st.top().second;
                dot -= st.top().first * st.top().second;
                st.pop();
            }
            
            st.push({A[i], count});
            dot += A[i] * count;
            ans += dot;
            ans %= MOD;
        }
        
        return ans;
    }
    
    int sumSubarrayMins1(vector<int>& A) {
        int ans = 0, MOD = 1e9+7;
        vector<int> left(A.size()), right(A.size());
        stack<pair<int, int>> st1, st2;
        
        for (int i = 0; i < A.size(); i++) {
            int count = 1;
            
            while (!st1.empty() && st1.top().first > A[i]) {
                count += st1.top().second;
                st1.pop();
            }
            
            st1.push({A[i], count});
            
            left[i] = count;
        }
        
        for (int i = A.size() - 1; i >= 0; i--) {
            int count = 1;
            
            while (!st2.empty() && st2.top().first >= A[i]) {
                count += st2.top().second;
                st2.pop();
            }
            
            st2.push({A[i], count});
            
            right[i] = count;
        }
        
        for (int i = 0; i < A.size(); i++) {
            ans += A[i] * left[i] * right[i] % MOD;
        }
        
        return ans;
    }
};