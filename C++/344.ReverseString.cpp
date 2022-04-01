class Solution {
public:
    void reverseString(vector<char>& s) {
        //1st pointer pointing to the start of the string
        int a = 0;
        //2nd pointer poiting to the end of the string
        int b = s.size()-1;

        //iterate over the string till a<=b
        while(a<=b)
        {
            //swap the 2 index values of the string
            swap(s[a], s[b]);
            a++;
            b--;
        }
    }
};

//TC: O(1), SC=O(1)
