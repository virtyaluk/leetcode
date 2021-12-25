class Leaderboard {
private:
    unordered_map<int, int> userToScore;
    multiset<int, greater<>> scores;
    
public:
    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        if (scores.find(userToScore[playerId]) != end(scores)) {
            scores.erase(scores.find(userToScore[playerId]));
        }
        
        userToScore[playerId] += score;
        scores.insert(userToScore[playerId]);
    }
    
    int top(int K) {
        int ans = 0;
        
        for (auto it = begin(scores); K > 0 and it != end(scores); K--, it++) {
            ans += *it;
        }
        
        return ans;
    }
    
    void reset(int playerId) {
        if (scores.find(userToScore[playerId]) != end(scores)) {
            scores.erase(scores.find(userToScore[playerId]));
        }
        
        userToScore[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */