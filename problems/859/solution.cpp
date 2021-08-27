class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        
        if (A == B) {
            set<char> s(begin(A), end(A));
            
            if (A.size() - s.size() != 0) {
                return true;
            }
        } else {
            set<char> sa, sb;
            int swaps = 0;
            
            for (int i = 0; i < A.size(); i++) {
                if(A[i] != B[i]) {
                    swaps++;
                    sa.insert(A[i]);
                    sb.insert(B[i]);
                }
            }
            
            if (swaps <= 2 && sa == sb) {
                return true;
            }
        }
        
        return false;
    }
    
    bool eq(set<char> const &lh, set<char> const &rh) {
        return true;
    }
};