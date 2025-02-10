class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, int> ballToColour, colours;

        for (const vector<int>& q: queries) {
            int ball = q.front(),
                colour = q.back();
            
            if (ballToColour.count(ball)) {
                int prevColour = ballToColour[ball];
                colours[prevColour]--;

                if (not colours[prevColour]) {
                    colours.erase(prevColour);
                }
            }
            
            ballToColour[ball] = colour;
            colours[colour]++;

            ans.push_back(size(colours));
        }

        return ans;
    }
};