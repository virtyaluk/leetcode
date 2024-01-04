class Solution {
public:
    string nearestPalindromic(string snum) {
        if (size(snum) == 1) {
            return to_string(stoll(snum) - 1);
        }
        
        int n = size(snum),
            mid = (n + 1) / 2;
        vector<long long> candidates = {(long long) pow(10, n - 1) - 1, (long long) pow(10, n) + 1},
            tmp;
        long long prefix = stoll(snum.substr(0, mid)),
            num = stoll(snum),
            ans = 0,
            dif = LONG_MAX;
        
        tmp.push_back(prefix);
        tmp.push_back(prefix - 1);
        tmp.push_back(prefix + 1);
        
        for (long long cand: tmp) {
            string postfix = to_string(cand);
            
            if (n % 2 != 0) {
                postfix.pop_back();
            }
            
            reverse(begin(postfix), end(postfix));
            candidates.push_back(stoll(to_string(cand) + postfix));
        }
        
        for (int i = 0; i < 5; i++) {
            if (candidates[i] != num and abs(candidates[i] - num) < dif) {
                dif = abs(candidates[i] - num);
                ans = candidates[i];
            } else if (abs(candidates[i] - num) == dif) {
                ans = min(ans, candidates[i]);
            }
        }
        
        return to_string(ans);
    }
};