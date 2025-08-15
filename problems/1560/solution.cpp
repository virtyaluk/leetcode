class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        int s = rounds.front(),
            e = rounds.back();
        
        if (e < s) {
            e += n;
        }

        for (int i = s; i <= e; i++) {
            int v = i % n;

            if (not v) {
                v = n;
            }

            ans.push_back(v);
        }

        sort(begin(ans), end(ans));

        return ans;
    }
};