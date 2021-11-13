class Robot {
public:
    Robot(int width, int height) {
        d_dir = 1;
        d_x = 0;
        d_y = 0;
        d_w = width;
        d_h = height;
        d_circle = ((unsigned long long)width+(unsigned long long)height-2)*2;
        d_index = 0;
    }
    
    void move(int num) {
        num %= d_circle;
        d_index += num;
        d_index %= d_circle;
        if (d_index == 0) {
            d_x = d_index;
            d_y = 0;
            d_dir = 2;
        } else if (d_index <= d_w-1) {
            d_x = d_index;
            d_y = 0;
            d_dir = 1;
        } else if (d_index <= d_w-1+d_h-1) {
            d_x = d_w-1;
            d_y = d_index-(d_w-1);
            d_dir = 0;
        } else if (d_index <= d_w-1+d_h-1+d_w-1) {
            d_x = d_w-1+d_h-1+d_w-1-d_index;
            d_y = d_h-1;
            d_dir = 3;
        } else {
            d_x = 0;
            d_y = d_w-1+d_h-1+d_w-1+d_h-d_index-1;
            d_dir = 2;
        }
    }
    
    vector<int> getPos() {
        return {d_x, d_y};
    }
    
    string getDir() {
        if (d_dir == 0) {
            return "North";
        }
        if (d_dir == 1) {
            return "East";
        }
        if (d_dir == 2) {
            return "South";
        }
        return "West";
    }
    
private:
    int d_dir;
    int d_x;
    int d_y;
    int d_w;
    int d_h;
    unsigned long long d_circle;
    int d_index;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
