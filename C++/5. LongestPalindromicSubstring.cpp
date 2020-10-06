class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        int max{};
        string ans;
        if(n == 1) return s;
        for(int i = 0; i < n; i++){
            int x = i, y = i;
            int count = 1;
            while(x > 0 && y < n - 1 && s[x - 1] == s[y + 1]){
                x--;
                y++;
                count += 2;
            }
            if(count > max){
                ans = s.substr(x, count);
                max = count;
            } 
            if(i < n - 1 && s[i] == s[i + 1]){
                int x = i, y = i + 1;
                count = 2;
                while (x > 0 && y < n - 1 && s[x - 1] == s[y + 1]){
                    x--;
                    y++;
                    count += 2;
                }
                if(count > max)
                {
                    ans = s.substr(x, count);
                    max = count;
                }
            }
        }
        return ans;
    }
};