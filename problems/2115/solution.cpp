class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        unordered_set<string> us(begin(supplies), end(supplies));
        unordered_map<string, int> rToIdx;
        unordered_map<string, unordered_set<string>> g;
        vector<int> indegree(size(recipes));
        queue<int> q;

        for (int i = 0; i < size(recipes); i++) {
            rToIdx[recipes[i]] = i;
        }

        for (int i = 0; i < size(recipes); i++) {
            for (const string& ing: ingredients[i]) {
                if (not us.count(ing)) {
                    g[ing].insert(recipes[i]);
                    indegree[i]++;
                }
            }
        }

        for (int i = 0; i < size(recipes); i++) {
            if (not indegree[i]) {
                q.push(i);
            }
        }

        while (not empty(q)) {
            int nextIdx = q.front();
            q.pop();

            string r = recipes[nextIdx];
            ans.push_back(r);

            if (not g.count(r)) {
                continue;
            }

            for (const string& nextR: g[r]) {
                if (not --indegree[rToIdx[nextR]]) {
                    q.push(rToIdx[nextR]);
                }
            }
        }

        return ans;
    }
};