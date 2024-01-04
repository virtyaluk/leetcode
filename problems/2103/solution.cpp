class Solution {
public:
    int countPoints(string rings) {
        vector<int> rods(10);
        unordered_map<char, int> um = {
            {'R', 1},
            {'G', 2},
            {'B', 4}
        };
        
        for (int i = 0; i < size(rings); i += 2) {
            rods[rings[i + 1] - '0'] |= um[rings[i]];
        }
        
        return count(begin(rods), end(rods), 1 | 2 | 4);
    }
};