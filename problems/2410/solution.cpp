class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans = 0;

        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        for (int i = 0, j = 0; i < size(players) and j < size(trainers);) {
            if (players[i] > trainers[j]) {
                j++;
            } else {
                i++;
                j++;
                ans++;
            }
        }

        return ans;
    }
};