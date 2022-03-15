class Solution {
public:
    string freqAlphabets(string s) {
        string mappedString;
        for(int i=0; i<s.size(); ++i)
        {
            if(i + 2 < s.size() && s[i+2] == '#')  //check i+2 condition before '#'
            {
                //dealing with 2 characters: one at unit's and one at ten's place
                mappedString += 'a' + 10 * (s[i] - '0') + s[i+1]-'1';
                i+=2;
            }
            else
            {
                //dealing with one character
                mappedString += 'a' + s[i] - '1';
            }
        }
        return mappedString;
    }
};

/*
    Example dry run:

    s = "10#11#12"
    s = 1  0  #  1  1  #  1  2  (size = 8)
    i = 0  1  2  3  4  5  6  7

   - We are obtaining the ASCII values keeping the given mapping in mind to generate decrypted strings
   - So if there is a '#' after 2 indices, we treat it as a 2-digit mathematical number, thereby multiplying the
     ten's place with 10 and removing '1' from the unit's place as given in the question, adding the value to
     'a' which returns the ascii value of the  characters originally; incrementing i by 2
   - Similarly, if there is no '#', we treat the character like unit's place

    i=0, i+2=='#'and i+2<8, therefore mappedString  += 'a' + 10 * (s[i] - '0') + s[i+1]-'1';
    i=1                                             => 97 + 10 * ('1' - '0') + '0' - '1'
                                                    => 97 + 10 * (49 - 48) + 48 - 49 =97 + 10 - 1=106 = j
    i+=2=3, i+2=='#' and i+2<8, so, mappedString += 'a' + 10 * (s[i] - '0') + s[i+1]-'1';
    i=4                                          =>j+ [97 + 10 * ('1' - '0')+'1'-'1']
                                                 =>j+ [97+10*(49-48)+0=97+10]=j + 107=jk
    i+=2=6, i+2!='#' and i+2<8, mappedString += 'a' + s[i] - '1';
    i=7                                      =>jk + [97 + '1' -'1'] = jk + [97] = jka

    i=7, i+2 doesn't exist since string length = 8, mappedString += 'a' + s[i] - '1';
    i=8                                                          =>jka + [97 + 98 - 97]=jka + [98]
                                                                 =>jka + [b] = jkab

    Output = jkab
*/
