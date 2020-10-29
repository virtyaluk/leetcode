class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(begin(strs), end(strs), [](const string& lhs, const string& rhs) {
            return size(lhs) > size(rhs);
        });
        
        for (int i = 0, j = 0; i < size(strs); i++) {
            bool flag = true;
            
            for (j = 0; j < size(strs); j++) {
                if (i == j) {
                    continue;
                }
                
                if (isSubsequence(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) {
                return size(strs[i]);
            }
        }
        
        return -1;
    }
    
    bool isSubsequence(const string& a, const string& b) {
        int j = 0;
        
        for (int i = 0; i < size(b) and j < size(a); i++) {
            if (a[j] == b[i]) {
                j++;
            }
        }
        
        return j == size(a);
    }
};