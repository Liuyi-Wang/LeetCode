class Solution {
public:
    string solveEquation(string equation) {
        int l_x = 0, l = 0, r_x = 0, r = 0;
        int begin = 0, end = 0;
        int sign = 1;
        equation += '=';
        for (; end < equation.size(); ++end) {
            if ('=' == equation[end] || 
                '+' == equation[end] ||
                '-' == equation[end]) {
                if ('x' == equation[end-1]) {
                    if (begin <= end-2) {
                        l_x += sign*atoi(equation.substr(begin, end-1-begin).c_str()); 
                    } else {
                        l_x += sign;    
                    }
                } else {    
                    l += sign*atoi(equation.substr(begin, end-begin).c_str());    
                }
                begin = end+1;
            }
            if ('=' == equation[end]) {
                break;
            }
            if ('+' == equation[end]) {
                sign = 1;
            }
            if ('-' == equation[end]) {
                sign = -1;
            }
        }
        ++end;
        sign = 1;
        for (; end < equation.size(); ++end) {
            if ('=' == equation[end] || 
                '+' == equation[end] ||
                '-' == equation[end]) {
                if ('x' == equation[end-1]) {
                    if (begin <= end-2) {
                        r_x += sign*atoi(equation.substr(begin, end-1-begin).c_str()); 
                    } else {
                        r_x += sign;    
                    }
                } else {    
                    r += sign*atoi(equation.substr(begin, end-begin).c_str());    
                }
                begin = end+1;
            }
            if ('=' == equation[end]) {
                break;
            }
            if ('+' == equation[end]) {
                sign = 1;
            }
            if ('-' == equation[end]) {
                sign = -1;
            }
        }
        l_x -= r_x;
        r -= l;
        if (0 == l_x && 0 == r) {
            return "Infinite solutions";
        }
        if (0 == l_x && 0 != r) {
            return "No solution";
        }
        int result = r/l_x;
        return "x="+to_string(result);
    }
};
