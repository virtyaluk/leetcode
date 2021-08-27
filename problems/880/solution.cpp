class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.size();
        long long size = 0;
        string s;
        
        for (char& ch: S) {
            if (isdigit(ch)) {
                size *= (ch - '0');
            } else {
                size++;
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            char ch = S[i];
            K %= size;
            
            if (K == 0 && isalpha(ch)) {
                s.push_back(ch);
                break;
            } else if (isdigit(ch)) {
                size /= (ch - '0');
            } else {
                size--;
            }
        }
        
        return s;
    }
};