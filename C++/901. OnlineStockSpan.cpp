// a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day

class StockSpanner {
    stack<pair<int,int> >prices;
 
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        
        while(!prices.empty() && prices.top().first <= price){
            cnt += prices.top().second;
            prices.pop();
        }
        
        prices.push({price,cnt});
        return cnt;
        
    }
};

