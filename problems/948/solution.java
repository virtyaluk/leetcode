class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        int score = 0;
        int lo = 0;
        int hi = tokens.length - 1;
        
        Arrays.sort(tokens);
        
        while (lo <= hi) {
            if (tokens[lo] <= P) {
                P -= tokens[lo];
                score++;
                lo++;
            } else if (score > 0) {
                if (lo == hi) {
                    break;
                }
                
                P += tokens[hi];
                score--;
                hi--;
            } else {
                break;
            }
        }
        
        return score;
    }
}