class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int i = 0, n = size(s);
        vector<string> zigZag(numRows);
        
        while (i < n) {
            for (int j = 0; j < numRows and i < n; j++) {
                zigZag[j].push_back(s[i++]);
            }
            
            for (int j = numRows - 2; j > 0 and i < n; j--) {
                zigZag[j].push_back(s[i++]);
            }
        }
        
        for (const string& zz: zigZag) {
            ans += zz;
        }
        
        return ans;
    }
};