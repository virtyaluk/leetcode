class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = size(transactions);
        vector<string> ans;
        vector<bool> invalid(n);
        vector<tuple<string, int, int, string>> parsed;
        unordered_map<string, vector<int>> um;
        
        for (int i = 0; i < n; i++) {
            istringstream iss(transactions[i]);
            vector<string> tac(4);
            
            for (int i = 0; getline(iss, tac[i], ','); i++);
            
            invalid[i] = stoi(tac[2]) >= 1000;
            
            for (const int& j: um[tac.front()]) {
                auto [ignore, prevTime, prevAmount, prevCity] = parsed[j];

                if (prevCity != tac.back() and abs(prevTime - stoi(tac[1])) <= 60) {
                    invalid[i] = true;
                    invalid[j] = true;
                }
            }
            
            um[tac.front()].push_back(i);
            parsed.push_back({
                tac.front(),
                stoi(tac[1]),
                stoi(tac[2]),
                tac.back()
            });
        }
        
        for (int i = 0; i < n; i++) {
            if (invalid[i]) {
                ans.push_back(transactions[i]);
            }
        }
        
        return ans;
    }
};