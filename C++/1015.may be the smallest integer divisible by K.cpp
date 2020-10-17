class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K%2 == 0 || K%5 == 0) return -1;
        int N = 1;
        int len = 1;
        while(N%K != 0){
            N = (N*10+1) % K;
            ++len;
        }
        return len;
    }
};
