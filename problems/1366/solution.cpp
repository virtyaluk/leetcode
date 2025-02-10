class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string ans;
        vector<vector<int>> freq(26, vector<int>(27));

        for (const char& ch: votes.front()) {
            freq[ch - 'A'].back() = ch;
        }

        for (const string& vote: votes) {
            for (int i = 0; i < size(vote); i++) {
                freq[vote[i] - 'A'][i]--;
            }
        }
        
        sort(begin(freq), end(freq));
        
        for (int i = 0; i < size(votes.front()); i++) {
            ans += freq[i].back();
        }
    
        return ans;
    }
};