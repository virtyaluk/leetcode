class Solution {
public:
    bool queryString(string s, int N) {
        int n = size(s);//, found = 0;
        // vector<bool> seen(N);
        unordered_set<int> seen;
        
        for (int i = 0; i < n and size(seen) < N; i++) {
            if (s[i] == '0') {
                continue;
            }
            
            for (int j = i, num = 0; j < n and num <= N; j++) {
                num = (num << 1) + (s[j] - '0');
                
                if (num > 0 and num <= N and not seen.count(num)) {
                    // found++;
                    seen.insert(num);
                }
            }
        }
        
        return size(seen) == N;
    }
};