typedef long long int ll;
const vector<ll> nums = {1, 2, 3, 11, 101, 111, 121, 22, 202, 212, 1001, 10001, 10101, 10201, 1111, 11011, 11111, 11211, 2002, 20002, 20102, 100001, 1000001, 1001001, 1002001, 101101, 1010101, 1011101, 1012101, 110011, 1100011, 1101011, 1102011, 111111, 1110111, 1111111, 200002, 2000002, 2001002, 10000001, 100000001, 100010001, 100020001, 10011001, 100101001, 100111001, 100121001, 10100101, 101000101, 101010101, 101020101, 10111101, 101101101, 101111101, 11000011, 110000011, 110010011, 110020011, 11011011, 110101011, 110111011, 11100111, 111000111, 111010111, 11111111, 111101111, 111111111, 20000002, 200000002, 200010002};

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        ll ans = 0, l = stoll(left), r = stoll(right);
        
        for (ll num: nums) {
            num *= num;
            
            if (num >= l and num <= r) {
                ans++;
            }
        }
        
        return ans;
    }
    
    int superpalindromesInRange2(string left, string right) {
        ll ans = 0, l = stoll(left), r = stoll(right);
        
        for (ll i = 1; i < 10; i++) {
            if (check(i, l, r)) {
                cout << i << endl;
                ans++;
            }
        }
        
        for (int i = 1; i <= 1e4; i++) {
            string one = to_string(i);
            string two = {rbegin(one), rend(one)};
            
            // check even-length palindrome
            if (check(stoll(one + two), l, r)) {
                cout << stoll(one + two) << endl;
                ans++;
            }
            
            for (int i = 0; i < 10; i++) {
                // check odd-length palindrome
                if (check(stoll(one + to_string(i) + two), l, r)) {
                    cout << stoll(one + to_string(i) + two) << endl;
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    bool check(const ll& val, const ll& left, const ll& right) {
        if (val > 1e9) {
            return false;
        }
        
        ll num = val * val;
        
        return num >= left and num <= right and isPal(num);
    }
    
    bool isPal(const ll& num) {
        string one = to_string(num);
        string two = {rbegin(one), rend(one)};
        
        return one == two;
    }
    
    int superpalindromesInRange1(string left, string right) {
        int ans = 0;
        ll l = stoll(left), r = stoll(right);
        vector<ll> vals;
        
        for (int i = 1; i < 10; i++) {
            vals.push_back(i);
        }
        
        for (int i = 1; i <= 1e4; i++) {
            string one = to_string(i);
            string two = {rbegin(one), rend(one)};
            
            vals.push_back(stoll(one + two));
            
            for (int i = 0; i < 10; i++) {
                vals.push_back(stoll(one + to_string(i) + two));
            }
        }
        
        for (const ll& v: vals) {
            if (v > 1e9) { // pow(10, 9)
                continue;
            }
            
            ll num = v * v;
            
            if (num >= l and num <= r and isPal(num)) {
                ans++;
            }
        }
        
        return ans;
    }
};