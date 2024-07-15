class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int> ans(size(a)), cnt(size(a) + 1);
        
        for (int i = 0, common = 0; i < size(a); i++) {
            common += ++cnt[a[i]] == 2;
            common += ++cnt[b[i]] == 2;
            ans[i] = common;
        }
        
        return ans;
    }
};