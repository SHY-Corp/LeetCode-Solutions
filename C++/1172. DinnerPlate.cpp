class DinnerPlates {
private:
    int popidx, pushidx, cap;
    vector<stack<int>> data;
    
public:
    DinnerPlates(int capacity) {
        cap = capacity;
        popidx = 0;
        pushidx = 0;
        data.push_back(stack<int>());
    }
    
    void push(int val) {
        if(data[pushidx].size() < cap){
            data[pushidx].push(val);
            return;
        }
        
        while(pushidx < data.size() && data[pushidx].size() == cap){
            pushidx++;
        }
        
        if(pushidx == data.size()){
            data.push_back(stack<int>());
            popidx = pushidx;
        }
        
        data[pushidx].push(val);
    }
    
    int pop() {
        if(data[popidx].size()){
            int ret = data[popidx].top();
            data[popidx].pop();
            return ret;
        }
        
        while(popidx > 0 && data[popidx].empty()){
            data.pop_back();
            popidx--;
        }
        
        if(popidx < pushidx) pushidx = popidx;
        
        if(data.size() == 1 && data[0].empty()) return -1;
        
        int ret = data[popidx].top();
        data[popidx].pop();
        
        return ret;
    }
    
    int popAtStack(int index) {
        if(data.size() <= index || data[index].empty()) return -1;
        int ret = data[index].top();
        data[index].pop();
        
        if(pushidx > index){
            pushidx = index;
        }
        
        return ret;
    }
}
