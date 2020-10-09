// Problem - 67 Add Binary 

// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contains only characters 1 or 0.


class Solution {
public:
    string addBinary(string a, string b) {
        
        string answer;                
        
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        int carry = 0;
        while(i>=0 || j>=0) {             // looping uptill the length of the larger number
            int sum = carry;
            if(i>=0)
                sum += a[i--] - '0';      
            if(j>=0)
                sum += b[j--] - '0';
            
            carry = sum > 1 ? 1 : 0;        // if sum > 1 carry is 1 otherwise 0 (because the base is 2)

            answer += to_string(sum%2);     // appending the remainder of sum/2 to answer string
        }
        
        if(carry)
            answer += to_string(carry);      // appending carry if any
        
        reverse(answer.begin(), answer.end());    // reversing the string to get required answer
        return answer;   
         
    }
};