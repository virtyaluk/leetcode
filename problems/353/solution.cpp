class SnakeGame {
private:
    int row = 0, col = 0, score = 0, foodIndex = 0, width, height;
    unordered_set<int> us;
    vector<vector<int>> food;
    deque<int> dq;

public:
    SnakeGame(int w, int h, vector<vector<int>>& f): width{w}, height{h}, food{f} {
        dq.push_back(0);
        us.insert(0);
    }
    
    int move(string dir) {
        if (dir == "L") {
            col--;
        } else if (dir == "R") {
            col++;
        } else if (dir == "U") {
            row--;
        } else if (dir == "D") {
            row++;
        }
        
        int key = row * 1e6 + col;
        
        if (row < 0 or row >= height or col < 0 or col >= width) {
            return -1;
        }
        
        if (us.count(key) and dq.front() != key) {
            return -1;
        }
        
        if (foodIndex < size(food) and food[foodIndex][0] == row and food[foodIndex][1] == col) {
            foodIndex++;
            score++;
        } else {
            us.erase(dq.front());
            dq.pop_front();
        }
        
        dq.push_back(key);
        us.insert(dq.back());
        
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */