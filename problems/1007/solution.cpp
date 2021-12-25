class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int ans = check(A[0], B, A, n);
        
        if (ans != -1 || A[0] == B[0]) {
            return ans;
        } else {
            return check(B[0], B, A, n);
        }
    }
    
    int check(int x, vector<int>& A, vector<int>& B, int n) {
        int rotA = 0, rotB = 0;
        
        for (int i = 0; i < n; i++) {
            if (A[i] != x && B[i] != x) {
                return -1;
            } else if (A[i] != x) {
                rotA++;
            } else if (B[i] != x) {
                rotB++;
            }
        }
        
        return min(rotA, rotB);
    }
};