class Solution {
public:
    string clearStars(string s) {
        string ans;
        vector<stack<int>> freq(26);

        for (int i = 0; i < size(s); i++) {
            if (s[i] != '*') {
                freq[s[i] - 'a'].push(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (not empty(freq[j])) {
                        s[freq[j].top()] = '*';
                        freq[j].pop();
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < size(s); i++) {
            if (s[i] != '*') {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};