class Solution {
public:
    string minimizeResult(string ex) {
        string ans;
        int n = size(ex),
            plusIdx = ex.find('+'),
            ansInt = INT_MAX;
        
        for (int i = 0; i < plusIdx; i++) {
            for (int j = plusIdx + 1; j < n; j++) {
                string a = ex.substr(0, i),
                    b = ex.substr(i, plusIdx - i),
                    c = ex.substr(plusIdx + 1, j - plusIdx),
                    d = ex.substr(j + 1);
                
                int ai = empty(a) ? 1 : stoi(a),
                    bi = empty(b) ? 1 : stoi(b),
                    ci = empty(c) ? 1 : stoi(c),
                    di = empty(d) ? 1 : stoi(d),
                    cur = ai * (bi + ci) * di;
                
                if (cur < ansInt) {
                    ansInt = cur;
                    ans = a + "(" + b + "+" + c + ")" + d;
                }
            }
        }
        
        return ans;
    }
};