typedef long long int i64;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans, candidate;
        function<void(int, i64, i64, i64, vector<string>&)> backtrack;
        
        backtrack = [&](int idx, i64 prevOp, i64 curOp, i64 val, vector<string>& cand) {
            if (idx == size(num)) {
                if (val == target and not curOp) {
                    string exp;
                    
                    for (int i = 1; i < size(cand); i++) {
                        exp += cand[i];
                    }
                    
                    ans.push_back(exp);
                }
                
                return;
            }
            
            curOp = curOp * 10 + (num[idx] - '0');
            string curOpStr = to_string(curOp);
            
            if (curOp > 0) {
                backtrack(idx + 1, prevOp, curOp, val, cand);
            }
            
            // +
            cand.push_back("+");
            cand.push_back(curOpStr);
            backtrack(idx + 1, curOp, 0, val + curOp, cand);
            cand.pop_back();
            cand.pop_back();
            
            if (not empty(cand)) {
                // -
                cand.push_back("-");
                cand.push_back(curOpStr);
                backtrack(idx + 1, -curOp, 0, val - curOp, cand);
                cand.pop_back();
                cand.pop_back();
                
                // *
                cand.push_back("*");
                cand.push_back(curOpStr);
                backtrack(idx + 1, curOp * prevOp, 0, val - prevOp + (prevOp * curOp), cand);
                cand.pop_back();
                cand.pop_back();
            }
        };
        
        backtrack(0, 0, 0, 0, candidate);
        
        return ans;
    }
};