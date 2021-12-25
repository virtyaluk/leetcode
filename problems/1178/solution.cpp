class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ans;
        unordered_map<int, int> um;
        
        for (const string& word: words) {
            int mask = 0;
            
            for (const char& ch: word) {
                mask |= 1 << (ch - 'a');
            }
            
            um[mask]++;
        }
        
        for (const string& puzzle: puzzles) {
            int first = 1 << (puzzle[0] - 'a'),
                count = um[first],
                mask = 0;
            
            for (int i = 1; i < size(puzzle); i++) {
                mask |= 1 << (puzzle[i] - 'a');
            }
            
            for (int submask = mask; submask; submask = (submask - 1) & mask) {
                count += um[submask | first];
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};