class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        return maxProfitSov2(inventory, orders);
    }
    
    int maxProfitSov1(vector<int>& inventory, int orders) {
        int M = 1e9+7;
        sort(inventory.begin(), inventory.end());
        inventory.insert(inventory.begin(), 0);
        long long result = 0;
        long long count = 1;
        long long prev = inventory.back();
        for(int i = static_cast<int>(inventory.size())-2; i >= 0; --i) {
            if (inventory[i] == prev) {
                ++count;
                continue;
            }
            int diff = prev - inventory[i];
            if (diff*count <= orders) {
                orders -= diff*count;
                result += count*((prev+inventory[i]+1)*(prev-inventory[i])/2);
                result %= M;
                ++count;
                prev = inventory[i];
            } else {
                long long temp = prev;
                while (orders >= count) {
                    result += temp*count;
                    orders -= count;
                    --temp;
                }
                result += temp*orders;
                result %= M;
                break;
            }
            if (orders == 0) {
                break;
            }
        }
        return result%M;
    }
    
    int maxProfitSov2(vector<int>& inventory, int orders) {
        int M = 1e9+7;
        int left = INT_MAX, right = INT_MIN;
        for (auto i:inventory) {
            left = min(left, i);
            right = max(right, i);
        }
        while (left + 1 < right) {
            int mid = left + (right-left)/2;
            if (valid(mid, inventory, orders)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        long long k = 0;
        if (valid(left, inventory, orders)) {
            k = left;
        } else {
            k = right;
        }
        long long result = 0;
        for (auto i:inventory) {
            if (i > k) {
                result += (i+k+1)*(i-k)/2;
                orders -= (i-k);
                result %= M;
            }
        }
        int size = inventory.size();
        long long K = k-orders/size;
        result += size*(k+K+1)*(k-K)/2;
        result %= M;
        orders -= (k-K)*size;
        if (orders > 0) {
            result += orders*K;
        }
        return result%M;
    }
    
    bool valid(int mid, vector<int>& inventory, int orders) {
        long long sum = 0;
        for (auto i:inventory) {
            if (i > mid) {
                sum += (i-mid);
                if (sum > orders) {
                    return false;
                }
            }
        }
        return true;
    }
    
};
