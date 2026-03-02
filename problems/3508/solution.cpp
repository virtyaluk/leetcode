class Router {
public:
    queue<vector<int>> q;
    int cap = 0;
    map<vector<int>, int> mpps;
    unordered_map<int, vector<int>> mppt;
    unordered_map<int, int> mppr;

    Router(int x) { 
        cap = x; 
    }

    bool addPacket(int s, int d, int t) {
        vector<int>packet = {s, d, t};

        if (mpps.count(packet) != 0) {
            return false;
        }

        if (size(q) == cap) { 
            vector<int> v = q.front();
            
            q.pop();
            mpps.erase(v);
            mppr[v[1]]++;
        }

        q.push(packet);
        mpps[packet]++;
        mppt[d].push_back(t);

        return true;
    }

    vector<int> forwardPacket() {
        if (empty(q)) {
            return {};
        }

        vector<int> v = q.front();

        q.pop();
        mpps.erase(v);
        mppr[v[1]]++;

        return v;
    }

    int getCount(int d, int st, int endT) {
        if (mppt.find(d) == mppt.end()) {
            return 0;
        }

        auto &v = mppt[d];
        int x = mppr[d];
        auto right = lower_bound(v.begin() + x, v.end(), st);
        auto left = upper_bound(v.begin() + x, v.end(), endT);

        return int(left - right);
    }
};