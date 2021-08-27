class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans(S.size() + 1);
        int lo = 0, hi = S.size();
        
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == 'I') {
                ans[i] = lo++;
            } else {
                ans[i] = hi--;
            }
        }
        
        ans[S.size()] = lo;
        
        return ans;
    }
};