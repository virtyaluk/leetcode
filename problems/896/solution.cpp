class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool dec = true, inc = true;
        
        for (int i = 1; i < A.size(); i++) {
            if (A[i - 1] > A[i]) {
                inc = false;
            }
            
            if (A[i - 1] < A[i]) {
                dec = false;
            }
            
            if (!dec && !inc) {
                return false;
            }
        }
        
        return dec || inc;
    }
};