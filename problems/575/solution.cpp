class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(begin(candyType), end(candyType));
        
        return min(candyType.size() / 2, s.size());
    }
};