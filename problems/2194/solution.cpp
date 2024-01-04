class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        char c1 = s[0],
            c2 = s[3],
            r1 = s[1],
            r2 = s[4];
        
        for (char c = c1; c <= c2; c++) {
            for (char r = r1; r <= max(r1, r2); r++) {
                string cell = "";
                cell.push_back(c);
                cell.push_back(r);
                
                ans.push_back(cell);
            }
        }
        
        return ans;
    }
};