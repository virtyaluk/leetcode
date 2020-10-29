class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        
        int ans = 0, dif = A[1] - A[0], inc = 1, lastIdx = 0;
        
        for (int i = 1; i < A.size(); i++) {
            if (A[i] - A[i - 1] == dif) {
                if (i - lastIdx >= 2) {
                    ans += inc++;
                }
            } else {
                inc = 1;
                dif = A[i] - A[i - 1];
                lastIdx = i - 1;
            }
        }
        
        return ans;
    }
};