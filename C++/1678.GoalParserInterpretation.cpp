class Solution {
public:
    string interpret(string command) {
        int n = command.size();
        string result="";

        for(int i=0; i<n; i++)
        {
            if(command[i]=='G')
                result = result + 'G';

            if(command[i]=='(' && command[i+1]==')')
            {
               result = result + 'o';
                i++;
            }
            if(command[i+1]=='a')
            {
                result = result + "al";
                i = i+3;
            }
        }
        return result;
    }
};

/*
TC = O(n), SC = O(1)

   G -> G
   () -> o
   (al) -> al

   For letter G, just check the ith index.
   For () and (al), check if i+1 is equal to either ')' or 'a'
       - if i+1 == ')' , append 'o' to the result and increment i by 1
       - if i+1 == 'a' , append "al" and increment i by 3, since (al) has 4 characters
*/
