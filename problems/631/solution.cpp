struct Cell {
    int val;
    unordered_map<int, int> sum;
    
    Cell(int v = 0): val{v} {}
};

class Excel {
private:
    int h;
    Cell table[27][27];
    
    unordered_map<int, int> parse(vector<string>& nums) {
        unordered_map<int, int> cnt;
        
        for (const string& num: nums) {
            if (size(num) == 2) {
                int col = num[0] - 'A',
                    row = stoi(num.substr(1));
                
                cnt[row * h + col]++;
            } else {
                istringstream iss(num);
                string tokens[2];
                
                getline(iss, tokens[0], ':');
                getline(iss, tokens[1], ':');
                
                int colStart = tokens[0][0] - 'A',
                    rowStart = stoi(tokens[0].substr(1)),
                    colEnd = tokens[1][0] - 'A',
                    rowEnd = stoi(tokens[1].substr(1));
                
                for (int i = colStart; i <= colEnd; i++) {
                    for (int j = rowStart; j <= rowEnd; j++) {
                        cnt[j * h + i]++;
                    }
                }
            }
        }
        
        return cnt;
    }

public:
    Excel(int height, char width): h{height} {}
    
    void set(int row, char col, int val) {
        table[row][col - 'A'].val = val;
        table[row][col - 'A'].sum.clear();
    }
    
    int get(int row, char col) {
        if (empty(table[row][col - 'A'].sum)) {
            return table[row][col - 'A'].val;
        }
        
        int ans = 0;
        
        for (auto [key, cnt]: table[row][col - 'A'].sum) {
            ans += cnt * get(key / h, 'A' + (key % h));
        }
        
        return ans;
    }
    
    int sum(int row, char col, vector<string> numbers) {
        table[row][col - 'A'].sum = parse(numbers);
        
        return get(row, col);
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */