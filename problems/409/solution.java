class Solution {
    public int longestPalindrome(String s) {
        if (s.length() == 0) {
            return 0;
        }
        
        int ans = 0;
        BitSet bits = new BitSet(2 * 26);
        
        for (char ch: s.toCharArray()) {
            int pos = 0;
            
            if (ch >= 'A' && ch <= 'Z') {
                pos = ch - 'A' + 26;
            } else {
                pos = ch - 'a';
            }
            
            if (bits.get(pos)) {
                ans += 2;
            }
            
            bits.flip(pos);
        }
        
        return Math.min(ans + 1, s.length());
    }
}