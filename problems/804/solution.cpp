class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> ans;
        vector<string> morseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for (string word: words) {
            stringstream ss;
            
            for (char ch: word) {
                ss << morseCode[ch - 'a'];
            }
            
            ans.insert(ss.str());
        }
    
        return ans.size();
    }
};