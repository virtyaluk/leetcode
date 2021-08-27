class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        
        for (int i = 2; i < s.size() - 1; i++) {
            string left = s.substr(1, i - 1),
                right = s.substr(i, s.size() - i - 1);
            vector<string> leftNums = getValidNumbers(left),
                rightNums = getValidNumbers(right);
            
            for (const string& lnum: leftNums) {
                for (const string& rnum: rightNums) {
                    ans.push_back("(" + lnum + ", " + rnum + ")");
                }
            }
        }
        
        return ans;
    }
    
    vector<string> getValidNumbers(const string& s) {    
        vector<string> ans;
        
        for (int i = 1; i <= s.size(); i++) {
            string left = s.substr(0, i),
                right = s.substr(i);
            
            if ((left[0] != '0' or left == "0") and right.back() != '0') {
                ans.push_back(left + (i < s.size() ? "." : "") + right);
            }   
        }
        
        return ans;
    }
};