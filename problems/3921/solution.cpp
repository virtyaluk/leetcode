class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0,
            counter = 0;
        
        for (int i = 0; i < size(events) and counter < 10; i++) {
            if (events[i] == "W") {
                counter++;
            } else if (events[i] == "WD" or events[i] == "NB") {
                score++;
            } else {
                score += events[i].front() - '0';
            }
        }

        return {score, counter};
    }
};