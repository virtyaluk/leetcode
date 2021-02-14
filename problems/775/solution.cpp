class Solution {
public:
    bool isIdealPermutation1(vector<int>& A) {
        vector<int> B = {begin(A), end(A)};
        
        sort(begin(B), end(B));
        
        for (int i = 0; i < A.size(); i++) {
            if (abs(A[i] - B[i]) > 1) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            if (abs(A[i] - i) > 1) {
                return false;
            }
        }
        
        return true;
    }
};