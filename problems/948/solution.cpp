class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if (tokens.empty()) {
            return 0;
        }
        
        if (tokens.size() == 1) {
            return tokens[0] <= P ? 1 : 0;
        }
        
        int score = 0, lo = 0, hi = tokens.size() - 1;
        
        sort(tokens.begin(), tokens.end());
        
        while (lo <= hi) {
            if (tokens[lo] <= P) {
                score++;
                P -= tokens[lo];
                lo++;
            } else if (score > 0) {
                if (lo == hi) {
                    break;
                }
                
                score--;
                P += tokens[hi];
                hi--;
            } else {
                break;
            }
        }
        
        return score;
    }
};