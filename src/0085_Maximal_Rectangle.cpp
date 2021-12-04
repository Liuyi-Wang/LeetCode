/**
 *  Time:
 *  O(mn)
 *  Sapce:
 *  O(n)
 */
class Solution {
    int largestRectangleArea(vector<int> heights) {
        heights.push_back(0);
        stack<int> stk;
        int result = 0;
        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                if (!stk.empty()) {
                    result = max(result, h*(i-1-stk.top()-1+1));
                } else {
                    result = max(result, h*(i-1+1));
                }
            }
            stk.push(i);
        }
        return result;
    }
public:
    /*
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == '1') {
                heights[j] = 1;
            }
        }
        int result = largestRectangleArea(heights);
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                    continue;
                }
                ++heights[j];
            }
            result = max(result, largestRectangleArea(heights));
        }
        return result;
    }*/
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        vector<int> l(n, -1);
        vector<int> r(n, n);
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                    continue;
                }
                ++heights[j];
            }
            int curl = -1, curr = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    l[j] = max(l[j], curl);
                } else {
                    curl = j;
                    l[j] = -1;
                }
            }
            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] =='1') {
                    r[j] = min(r[j], curr);
                } else {
                    curr = j;
                    r[j] = n;
                }
            }
            for (int j = 0; j < n; ++j) {
                result = max(result, heights[j]*(r[j]-1-l[j]-1+1));
            }
        }
        return result;
    }
};
