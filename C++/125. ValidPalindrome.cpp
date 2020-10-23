// First of all, made a string p using string s with all tha characters which can be a part of the palindrome, which means, considering only alphanumeric characters and ignoring cases.
// Then using while loop, traversed string p from both sides (from the beginning as well as the end) to check if it forms a palindrome.

bool isPalindrome(string s) {
    string p;        
    for(int i=0;i<s.size();i++)
    {
        if(isupper(s[i]))
        {
            s[i]+=32;
            p+=s[i];
        }
        
        else if(islower(s[i]))
            p+=s[i];
            
        else if(isdigit(s[i]))
            p+=s[i];
    }
    
    int i=0,j=p.size()-1;
    while(i<=j)
    {
        if(p[i]!=p[j])
            return false;
        i++;
        j--;
    }
    return true;
}
