/* program name:- Roman_To_Integer.cpp
This program converts the entered roman number to integer .
We have used the hash map to ease the input for the desired roman representation of an integer.
*/



int romanToInt(string s) {
        
        map<char, int> m = {{'I', 1}, {'V', 5},{'X', 10},{'L', 50},
        {'C', 100},{'D', 500},{'M', 1000}};
        
        int total = 0;
        for(int i = 0; i < s.length(); i++){
            
            //1.The letters are arranged from left to right 
              in descending order of value to form a number
            
            if(m[s[i+1]] <= m[s[i]])  total += m[s[i]]; 
            
            //2.when you see a lower value in front of a 
               higher value (subtract)
            else  total -= m[s[i]];  
        }
        return total;
    }
