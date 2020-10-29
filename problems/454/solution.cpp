class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int, int> m1, m2;
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                m1[A[i] + B[j]]++;
            }
        }
        
        for (int k = 0; k < C.size(); k++) {
            for (int l = 0; l < D.size(); l++) {
                m2[C[k] + D[l]]++;
            }
        }
        
        for (auto [sum, freq]: m1) {
            int dif = 0 - sum;
            
            if (m2.find(dif) != m2.end()) {
                ans += freq * m2[dif];
            }
        }
        
        return ans;
    }
};