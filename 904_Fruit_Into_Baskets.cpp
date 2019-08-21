class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int fi = 0, fc = 1;
        int si;
        int sc = 0;
        int index = 1;
        while (index < tree.size()) {
            if (tree[index] != tree[fi]) {
                sc = 1;
                si = index++;
                break;
            }
            ++fc;
            ++index;
        }
        int result = index-fi;
        while (index < tree.size()) {
            if (tree[index] ==  tree[fi]) {
                ++fc;
                ++index;
                continue;
            }
            if (tree[index] == tree[si]) {
                ++sc;
                ++index;
                continue;
            }
            result = max(result, index-fi);
            int j = fi;
            while (j < index && fc > 0 && sc > 0) {
                if (tree[j] == tree[fi]) {
                    --fc;
                    ++j;
                    continue;
                }
                if (tree[j] == tree[si]) {
                    --sc;
                    ++j;
                    continue;
                }
            }
            fi = j;
            si = index;
            if (0 == fc) {
                fc = sc;
            }
            sc = 1;
            
            ++index;
            result = max(result, index-fi);
        }
        result = max(result, index-fi);
        return result;
    }    
};
