map<int,vector<int> > b;
set<pair<pair<int,int>,int> > c;
int p;

class FreqStack {
public:
    FreqStack() {
        p=0;
        b.clear();
        c.clear();
    }
    void push(int x) {
        if(b[x].size() && c.find({{b[x].size(),b[x][b[x].size()-1]},x})!=c.end())
            c.erase({{b[x].size(),b[x][b[x].size()-1]},x});
        b[x].push_back(p);
        c.insert({{b[x].size(),p},x});
        p++;
    }
    int pop() {
        set<pair<pair<int,int>,int> >::iterator it;
        int x;
        it=--c.end();
        x=it->second;
        c.erase(it);
        b[x].pop_back();
        if(b[x].size())
            c.insert({{b[x].size(),b[x][b[x].size()-1]},x});
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
