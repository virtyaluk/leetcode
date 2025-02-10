class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<char, int>> sq, tq;
        
        for (int i = 0; i < size(start); i++) {
            if (start[i] != '_') {
                sq.push({start[i], i});
            }
            
            if (target[i] != '_') {
                tq.push({target[i], i});
            }
        }
        
        if (size(sq) != size(tq)) {
            return false;
        }
        
        while (not empty(sq)) {
            auto [sCh, sIdx] = sq.front();
            auto [tCh, tIdx] = tq.front();
            
            sq.pop();
            tq.pop();
            
            if (sCh != tCh or (sCh == 'L' and sIdx < tIdx) or (sCh == 'R' and sIdx > tIdx)) {
                return false;
            }
        }
        
        return true;
    }
};