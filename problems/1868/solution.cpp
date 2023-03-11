class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int i = 0, j = 0, m = size(encoded1), n = size(encoded2);
        vector<vector<int>> ans;
        
        while (i < m and j < n) {
            if (not encoded1[i][1]) {
                i++;
            } else if (not encoded2[j][1]) {
                j++;
            } else {
                int product = encoded1[i][0] * encoded2[j][0],
                    count = min(encoded1[i][1], encoded2[j][1]);
                
                encoded1[i][1] -= count;
                encoded2[j][1] -= count;
                
                if (empty(ans) or product != ans.back().front()) {
                    ans.push_back({product, count});
                } else {
                    ans.back().back() += count;
                }
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> findRLEArray1(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> ans;
        vector<int> first, second, third;
        
        for (const vector<int>& enc: encoded1) {
            for (int i = 0; i < enc[1]; i++) {
                first.push_back(enc[0]);
            }
        }
        
        for (const vector<int>& enc: encoded2) {
            for (int i = 0; i < enc[1]; i++) {
                second.push_back(enc[0]);
            }
        }
        
        for (int i = 0; i < size(first); i++) {
            third.push_back(first[i] * second[i]);
        }
        
        for (int i = 0; i < size(third); i++) {
            if (empty(ans) or third[i] != ans.back().front()) {
                ans.push_back({third[i], 1});
            } else {
                ans.back().back()++;
            }
        }
        
        return ans;
    }
};