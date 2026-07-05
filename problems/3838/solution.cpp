class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (const string& word: words) {
            int w = 0;

            for (const char& ch: word) {
                w += weights[ch - 'a'];
            }

            w = w % 26;

            ans.push_back('z' - w);
        }

        return ans;
    }
};