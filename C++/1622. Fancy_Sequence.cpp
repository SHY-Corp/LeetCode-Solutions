const int mod = 1e9+7;
class Fancy {
    vector<int> ret;
    vector<pair<int, int>> addmul;
    vector<int> addmul_idx;
public:
    Fancy() {
       // vector<int> ret;
    }
    
    void append(int val) {
        ret.push_back(val);
    }
    
    void addAll(int inc) {
        addmul_idx.push_back((int)ret.size()-1);
        addmul.emplace_back(0, inc);
    }
    
    void multAll(int m) {
        addmul_idx.push_back((int)ret.size()-1);
        addmul.emplace_back(1, m);
    }
    int getIndex(int idx) {
        if (idx>=ret.size()) return -1;
        long long this_ret = ret[idx];
        int begin_idx = lower_bound(addmul_idx.begin(), addmul_idx.end(), idx) - addmul_idx.begin();
        for (int i = begin_idx; i < addmul.size();++i) {
            auto [operation, val] = addmul[i];
            if (operation == 0) {
                this_ret += val;
            }
            else {
                this_ret *= val;
            }
            if (this_ret >= mod) this_ret %= mod;  
        }
        return this_ret;    
    }
};
