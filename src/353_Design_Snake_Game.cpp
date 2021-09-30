class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        d_w = width;
        d_h = height;
        for (const auto &f:food) {
            d_f.push({f[0], f[1]});
        }
        d_j = {0, 0, -1, 1};
        d_i = {-1, 1, 0, 0};
        d_s.push({0, 0});
        d_fl = d_f.size();
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int d;
        if ("U" == direction) {
            d = 0;
        } else if ("D" == direction) {
            d = 1;
        } else if ("L" == direction) {
            d = 2;
        } else if ("R" == direction) {
            d = 3;
        }
        pair<int, int> head = d_s.front();
        int l = d_s.size();
        if (head.first+d_i[d] < 0 || head.first+d_i[d] >= d_h) {
            return -1;
        } else {
            head.first += d_i[d];
        }
        if (head.second+d_j[d] < 0 || head.second+d_j[d] >= d_w) {
            return -1;
        } else {
            head.second += d_j[d];
        }
        d_s.push(head);
        while (l > 1) {
            if (head.first == d_s.front().first && head.second == d_s.front().second) {
                return -1;
            }
            d_s.push(d_s.front());
            d_s.pop();
            --l;
        }
        if (!d_f.empty() && head.first == d_f.front().first && head.second == d_f.front().second) {
            d_f.pop();
            d_s.push(d_s.front());
        }
        d_s.pop();
        return d_fl-d_f.size();
    }
    
private:
    int d_w;
    int d_h;
    queue<pair<int, int>> d_f;
    queue<pair<int, int>> d_s;
    vector<int> d_i;
    vector<int> d_j;
    int d_fl;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
