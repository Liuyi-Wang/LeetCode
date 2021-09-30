class Solution {
public:
    bool less_than (int i1, int i2) {
        if (d_m.find(i1) == d_m.end() && d_m.find(i2) == d_m.end()) {
            return i1 < i2;
        }
        if (d_m.find(i1) == d_m.end()) {
            return false;
        } 
        if (d_m.find(i2) == d_m.end()) {
            return true;
        }
        return d_m[i1] < d_m[i2];
    }
    
    int partition(vector<int>& arr, int begin, int end) {
        int p = arr[end];
        int index = begin;
        for (int i = begin; i < end; ++i) {
            if (less_than(arr[i], p)) {
                swap(arr[index++], arr[i]);
            }
        }
        swap(arr[index], arr[end]);
        return index;
     }
    
    void quickSort(vector<int>& arr, int begin, int end) {
        if (begin < end) {
            int p = partition(arr, begin, end);
            quickSort(arr, begin, p-1);
            quickSort(arr, p+1, end);
        }
    }
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        for (int i = 0; i < arr2.size(); ++i) {
            d_m[arr2[i]] = i;
        }
        quickSort(arr1, 0, arr1.size()-1);
        return arr1;
    }
private:
    unordered_map<int, int> d_m;
};
