class Solution {
private:
    bool isKRepeatedSubsequence(const string& s, const string& t, int k) {
        int idx = 0,
            match = 0,
            n = size(s),
            m = size(t);
        
        for (const char& ch: s) {
            if (ch == t[idx]) {
                idx++;

                if (idx == m) {
                    idx = 0;
                    match++;

                    if (match == k) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans = "";
        vector<int> freq(26);
        vector<char> candidate;
        queue<string> q;

        for (const char& ch: s) {
            freq[ch - 'a']++;
        }

        for (int i = 25; i >= 0; i--) {
            if (freq[i] >= k) {
                candidate.push_back('a' + i);
            }
        }

        for (const char& ch: candidate) {
            q.push(string(1, ch));
        }

        while (not empty(q)) {
            string cur = q.front();
            q.pop();

            if (size(cur) > size(ans)) {
                ans = cur;
            }

            for (const char& ch: candidate) {
                string next = cur + ch;

                if (isKRepeatedSubsequence(s, next, k)) {
                    q.push(next);
                }
            }
        }

        return ans;
    }
};