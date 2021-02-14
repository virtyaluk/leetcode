#define ll long long

class disjoint_set {
private:
    vector<ll> id, rank;
    ll size;

public:
    disjoint_set(ll n) {
        size = n;
        
        id.resize(n);
        // rank.resize(n, 1);
        iota(id.begin(), id.end(), 0);
    }
    
    ll find(ll p) {
//         ll root = p;
//         //find the root
//         while(root != id[root]) {
//             root = id[root];
//         }

//         //perform path compression
//         while(p != root) {
//             ll newp = id[p];
//             id[p] = root;
//             p = newp;
//         }

//         return root;
        if (id[p] != p) {
            id[p] = find(id[p]);
        }
        
        return id[p];
    }
    
    bool merge(ll x, ll y) {
//         x = find(x);
//         y = find(y);

//         if (x == y) {
//             return false;
//         }

//         if (rank[x] > rank[y]) {
//             id[y] = x;
//         } else {
//             id[x] = y;
//         }

//         if (rank[x] == rank[y]) {
//             rank[y] += 1;
//         }

//         return true;
        id[find(x)] = find(y);
        return false;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        disjoint_set ds(10001);
        unordered_map<string, string> emailToName;
        unordered_map<string, int> emailIds;
        unordered_map<int, vector<string>> idToEmails;
        
        for (int i = 0; i < size(accounts); i++) {
            string name = accounts[i][0];
            
            for (int j = 1; j < size(accounts[i]); j++) {
                emailToName[accounts[i][j]] = name;
                
                if (not emailIds.count(accounts[i][j])) {
                    emailIds[accounts[i][j]] = size(emailIds);
                }

                ds.merge(emailIds[accounts[i][1]], emailIds[accounts[i][j]]);
            }
        }
        
        for (auto [email, ignore]: emailToName) {
            int id = ds.find(emailIds[email]);
            idToEmails[id].push_back(email);
        }
        
        for (auto [ignore, emails]: idToEmails) {
            sort(begin(emails), end(emails));
            emails.insert(begin(emails), emailToName[emails[0]]);
            ans.push_back(emails);
        }
        
        return ans;
    }
};