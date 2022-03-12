class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        //pointers for word1 and word2 respectively
        int a = 0, b = 0;
        int n = word1.size();
        int m = word2.size();
        string result="";

        //iterating over word1 and word2, thereby pushing characters from each word alternatively
        while(a<n || b<m)
        {
            //updating the output string with a character from word1 till a<n
            if(a<n)
                result = result + word1[a];

            //updating the string again with a character from word2
            if(b<m)
                result = result + word2[b];

            a++;
            b++;
        }
        return result;
    }
};
