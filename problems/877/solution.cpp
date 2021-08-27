class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int all = accumulate(begin(piles), end(piles), 0),
            alex = 0, lo = 0, hi = size(piles) - 1;
        
        while (lo <= hi) {
            if (hi - lo > 2) {
                if (piles[lo] + piles[hi - 1] >= piles[hi] + piles[lo + 1]) {
                    alex += piles[lo++];
                } else {
                    alex += piles[hi--];
                }
            } else {
                alex += max(piles[lo++], piles[hi--]);
            }
        }
        
        return alex > all / 2;
    }
    
    bool stoneGame1(vector<int>& piles) {
        int alex = 0, lee = 0, lo = 0, hi = size(piles) - 1;
        bool turn = true;
        
        while (lo <= hi) {
            if (turn) {
                if (piles[lo] >= piles[hi]) {
                    alex += piles[lo++];
                } else {
                    alex += piles[hi--];
                }
            } else {
                if (piles[lo] <= piles[hi]) {
                    lee += piles[lo++];
                } else {
                    lee += piles[hi--];
                }
            }
            
            turn = !turn;
        }
        
        return alex > lee;
    }
};