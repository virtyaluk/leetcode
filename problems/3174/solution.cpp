class Solution {
public:
    string clearDigits(string s) {
        string ans;
        stack<int> nonDigitIdxs;
        unordered_set<int> toDelete;
        
        for (int i = 0; i < size(s); i++) {
            if (isdigit(s[i])) {
                toDelete.insert(i);
                
                if (not empty(nonDigitIdxs)) {
                    toDelete.insert(nonDigitIdxs.top());
                    nonDigitIdxs.pop();
                }
            } else {
                nonDigitIdxs.push(i);
            }
        }
        
        for (int i = 0; i < size(s); i++) {
            if (not toDelete.count(i)) {
                ans.push_back(s[i]);
            }
        }
        
        return ans;
    }
};