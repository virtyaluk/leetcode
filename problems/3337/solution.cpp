const int MOD = 1e9+7;

class Solution {
private:
    vector<vector<long long>> matMul(vector<vector<long long>> mat1, vector<vector<long long>> mat2) {
        int m = size(mat1),
            n = size(mat1[0]),
            p = size(mat2[0]);
        vector<vector<long long>> ans(m, vector<long long>(p));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < p; j++) {
                long long input = 0;
                
                for (int k = 0; k < n; k++) {
                    ans[i][j] += (mat1[i][k] * mat2[k][j]);
                    ans[i][j] %= MOD;
                }
            }
        }

        return ans;
    }
    vector<vector<long long>> powerExp(vector<vector<long long>> mat,int t) {
        if (t == 1) {
            return mat;
        }

        vector<vector<long long>> half = powerExp(mat, t/2);

        if (t%2 == 0) {
            return matMul(half, half);
        } else {
            return matMul(matMul(half, half), mat);
        }
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        long long ans = 0;
        vector<vector<long long>> mat(26, vector<long long>(26)),
            newNum(1, vector<long long>(26));
        
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < nums[i]; j++){
                mat[i][(i + j + 1) % 26]++;
            }
        }

        mat = powerExp(mat, t);
        
        for (const char& ch: s) {
            newNum[0][ch - 'a']++;
        }

        newNum = matMul(newNum, mat);

        for (int i = 0; i < 26; i++) {
            ans += newNum[0][i];
            ans %= MOD;
        }

        return ans;
    }
};