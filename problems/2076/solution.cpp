class Solution {
private:
    vector<int> vi;

    int uf(int i) {
        return vi[i] == -1 ? i : vi[i] = uf(vi[i]);
    }

public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        vi.resize(n, -1);

        for (const vector<int>& r: requests) {
            int x = r[0],
                y = r[1],
                cx = uf(x),
                cy = uf(y);
            
            if (cx != cy) {
                bool isValid = true;

                for (const vector<int>& rr: restrictions) {
                    if ((uf(rr[0]) == cx and uf(rr[1]) == cy) or (uf(rr[1]) == cx and uf(rr[0]) == cy)) {
                        isValid = false;

                        break;
                    }
                }

                if (isValid) {
                    vi[cx] = cy;
                    ans.push_back(true);
                } else {
                    ans.push_back(false);
                }
            } else {
                ans.push_back(true);
            }
        }

        return ans;
    }
};