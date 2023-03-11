class Solution {
private:
    void dfs(bitset<100001>& bs, const vector<bool>& state, const int n, const int node, bool flip) {
        if (node > n) {
            return;
        }
        
        if (state[node]) {
            flip = !flip;
        }
        
        if (flip) {
            bs.set(node, 1 - bs[node]);
        }
        
        dfs(bs, state, n, node * 2, flip);
        dfs(bs, state, n, node * 2 + 1, flip);
    }
public:
    int numberOfNodes(int n, vector<int>& queries) {
        bitset<100001> bs;
        vector<bool> state(n + 1);
        
        for (const int& node: queries) {
            state[node] = !state[node];
        }
        
        dfs(bs, state, n, 1, false);
        
        return bs.count();
    }
};