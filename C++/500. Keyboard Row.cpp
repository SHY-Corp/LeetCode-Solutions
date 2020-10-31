//500| Keyboard Row
/* Statement:
** Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
** Input: ["Hello", "Alaska", "Dad", "Peace"]
** Output: ["Alaska", "Dad"]
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<char> line1 {'q','w','e','r','t','y','u','i','o','p'};
        vector<char> line2 {'a','s','d','f','g','h','j','k','l'};
        vector<char> line3 {'z','x','c','v','b','n','m'};
        //Insert first line
        vector<char>::iterator it1, it2, it3;
        vector<string>::iterator strIt;
        vector<string> output;
        int i;
        for (strIt=words.begin();strIt!=words.end();strIt++) {
            string temp = *strIt;
            it1 = find(line1.begin(), line1.end(), tolower(temp[0]));
            it2 = find(line2.begin(), line2.end(), tolower(temp[0]));
            it3 = find(line3.begin(), line3.end(), tolower(temp[0]));
            if (it1 != line1.end()) {
                for(i=1;i<temp.size();i++){
                    it1 = find(line1.begin(), line1.end(), tolower(temp[i]));
                    if(it1 == line1.end())
                        break;
                }
                if(i==temp.size())
                    output.push_back(temp);
            } else if(it2 != line2.end()) {
                for(i=1;i<temp.size();i++){
                    it2 = find(line2.begin(), line2.end(), tolower(temp[i]));
                    if(it2 == line2.end())
                        break;
                }
                if(i==temp.size())
                    output.push_back(temp);
            } else if(it3 != line3.end()) {
                for(i=1;i<temp.size();i++){
                    it3 = find(line3.begin(), line3.end(), tolower(temp[i]));
                    if(it3 == line3.end())
                        break;
                }
                if(i==temp.size())
                    output.push_back(temp);
            }
        }
        return output;
    }
};