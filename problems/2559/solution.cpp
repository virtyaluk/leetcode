class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> us{'a', 'e', 'i', 'o', 'u'};
        vector<int> ans,
            cnt;
        
        for (const string& w: words) {
            cnt.push_back(empty(cnt) ? 0 : cnt.back());
            cnt.back() += us.count(w.front()) and us.count(w.back());
        }

        for (const vector<int>& q: queries) {
            int cur = q.back() >= size(words) ? cnt.back() : cnt[q.back()];

            if (q.front() - 1 >= 0) {
                cur -= cnt[q.front() - 1];
            }

            ans.push_back(cur);
        }

        return ans;
    }
};