
//Implement FreqStack, a class which simulates the operation of a stack-like data structure.
//
//FreqStack has two functions:
//
//push(int x), which pushes an integer x onto the stack.
//pop(), which removes and returns the most frequent element in the stack.
//If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.


#include <bits/stdc++.h>

using namespace std;


class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int> > st;
    int maxFrequency = 0;
public:
    FreqStack() {

    }

    void push(int x) {
        freq[x]++;
        if (freq[x] > maxFrequency)
            maxFrequency = freq[x];
        st[freq[x]].push(x);
    }

    int pop() {
        int target = st[maxFrequency].top();
        freq[target]--;
        st[maxFrequency].pop();
        if (st[maxFrequency].size() == 0)
            maxFrequency--;
        return target;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    FreqStack* obj = new FreqStack();
    obj->push(5);
    cout << obj->pop()<<endl;



}