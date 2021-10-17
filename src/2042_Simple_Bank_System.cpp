class Bank {
public:
    Bank(vector<long long>& balance) {
        d_balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        int b1 = account1-1, b2 = account2-1;
        if (b1 >= d_balance.size() || b2 >= d_balance.size()) {
            return false;
        }
        if (d_balance[b1] < money) {
            return false;
        }
        d_balance[b1] -= money;
        d_balance[b2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        int b = account-1;
        if (b >= d_balance.size()) {
            return false;
        }
        d_balance[b] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        int b = account-1;
        if (b >= d_balance.size()) {
            return false;
        }
        if (d_balance[b] < money) {
            return false;
        }
        d_balance[b] -= money;
        return true;
    }
    
private:
    vector<long long> d_balance;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
