class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = size(status),
            ans = 0;
        queue<int> q;
        vector<bool> canOpen(n),
            hasBox(n),
            used(n);
        
        for (int i = 0; i < n; i++) {
            canOpen[i] = status[i] == 1;
        }

        for (const int& box: initialBoxes) {
            hasBox[box] = true;

            if (canOpen[box]) {
                q.push(box);
                used[box] = true;
                ans += candies[box];
            }
        }

        while (not empty(q)) {
            int bigBox = q.front();
            q.pop();

            for (const int& key: keys[bigBox]) {
                canOpen[key] = true;

                if (not used[key] and hasBox[key]) {
                    q.push(key);
                    used[key] = true;
                    ans += candies[key];
                }
            }

            for (const int& box: containedBoxes[bigBox]) {
                hasBox[box] = true;

                if (not used[box] and canOpen[box]) {
                    q.push(box);
                    used[box] = true;
                    ans += candies[box];
                }
            }
        }

        return ans;
    }
};