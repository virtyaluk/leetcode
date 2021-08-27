class TopVotedCandidate {
private:
    map<int, int> votes;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> freq;
        int leader = 0;
        
        for (int i = 0; i < size(persons); i++) {
            freq[persons[i]]++;
            
            if (freq[persons[i]] >= freq[leader]) {
                leader = persons[i];
            }
            
            votes[times[i]] = leader;
        }
    }
    
    int q(int t) {
        auto it = votes.upper_bound(t);
        
        return prev(it)->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */