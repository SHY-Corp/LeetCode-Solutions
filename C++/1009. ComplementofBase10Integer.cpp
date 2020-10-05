class Solution
{
public:
    int bitwiseComplement(int N) {
        
        if(N == 0) return 1;
        int x = 0;
        for(int i = 1; i <= N; i <<= 1)
        {
            x += !(i & N) * i;
        }
        return x;
    }
};
