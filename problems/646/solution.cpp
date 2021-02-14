class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0, cur = INT_MIN;

        sort(pairs.begin(), pairs.end(), [](vector<int>& lhs, vector<int>& rhs) {
           return lhs[1] < rhs[1]; 
        });
        
        for (vector<int> pair: pairs) {
            if (cur < pair[0]) {
                cur = pair[1];
                ans++;
            }
        }
        
        return ans;
    }
};