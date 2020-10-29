// Convert integers to Roman Numerals

class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        map<char,int>m;
        m['I'] =1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int index = 0;
     
        for(int i=s.length()-1;i>=0;i--){
            if(m[s[i]]>=index){
                num+=m[s[i]];   
            }else{
                num-=m[s[i]];
            }
            index = m[s[i]];
                
        }
        return num;
    }
};