class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size(), -1);
        vector<pair<int, int>> bc;
        int lo = 0, hi = A.size() - 1;
        
        for (int i = 0; i < B.size(); i++) {
            bc.push_back({B[i], i});
        }
        
        sort(begin(A), end(A), greater<int>());
        sort(begin(bc), end(bc), greater<pair<int, int>>());

        for (auto [num, i]: bc) {
            if (A[lo] > num) {
                ans[i] = A[lo++];
            } else {
                ans[i] = A[hi--];
            }
        }
        
        return ans;
    }
};