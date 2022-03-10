class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)
            return true;

        vector<int> temp;
        int n = s1.size();  //or s2.size()

        for(int i=0; i<n; i++)
        {
            if(s1[i] != s2[i])
                temp.push_back(i); //storing indices of those characters which do not match
        }

        //since we can only swap 2 indices, if the size is more than 2, it implies that there are
        //lots of different characters between the strings and there is no point swapping
        if(temp.size()==2)
        {
            int a = temp[0];
            int b = temp[1];

            //checking if the 2 unmatched characters exist in the other string
            if(s1[a]==s2[b] && s1[b]==s2[a])
                return true;
        }
        return false;
    }
};

/*
  Explanation through example:
  s1 = bank
  s2 = kanb

  s1[0] != s2[0], temp[0] = 0
  s1[1] == s2[1]
  s1[2] == s2[2]
  s1[3] != s2[3], temp[1] = 3

  temp = [0,3]: indices of unmatched characters
  a = temp[0] = 0, b = temp[1] = 3

  s1[a] = s1[0] = b, s2[b] = s2[3] = b
               AND
  s1[b] = s1[3] = k, s2[a] = s2[0] = k

  They are equal! So, return true.

*/
