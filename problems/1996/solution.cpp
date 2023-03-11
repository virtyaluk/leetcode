class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans = 0, n = size(properties);
        
        sort(begin(properties), end(properties), [](const vector<int>& lhs, const vector<int>& rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] > rhs[1];
            }
            
            return lhs[0] < rhs[0];
        });
        
        for (int i = n - 2, curMax = properties.back().back(); i >= 0; i--) {
            if (properties[i][1] < curMax) {
                ans++;
            }
            
            curMax = max(curMax, properties[i][1]);
        }
        
        return ans;
    }
};

/*

[[1,5],[10,4],[4,3]]
[[1, 5], [4, 3], [10, 4]]

*/