//925. Long Pressed Name
/* Statement:
**Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
**You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.size();
        int n = typed.size();
        int i=1, j=0;
        string temp = "";
        //to handle the case of first incorrect character
        temp += typed[0];
        if (typed[0]==name[0])
            j++;
        while (i<n) {
            if (name[j] == typed[i]){
                temp += typed[i];
                j++;
            } else if (i-1>0 && (typed[i] != typed[i-1])) {
                temp += typed[i];
            }
            i++;
        }
        if (temp == name)
            return true;
        else
            return false;
    }
};