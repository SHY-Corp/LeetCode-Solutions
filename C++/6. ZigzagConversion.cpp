/*
   	P   A   H   N
	A P L S I I G
	Y   I   R
	
	Imagine it as a matrix of given number of rows (numRows).
	Iterate through each row and print the characters.
	-For first and last row increment the value of currentRow with 2*(numRows-1)
	-For middle rows:
		- if going in upward direction increment currentRow by 2*(numRows - i - 1)
		- if going in downward direction increment currentRow by 2*i 
	
*/
class Solution {
public:
    string convert(string s, int numRows) {
	//check if number of rows are less than or equal to 1
        if(numRows<=1)
            return s;
        string str;
        int len = s.length();
        //loop through 0 to numRows-1
        for(int i =0;i<numRows;i++)
        {
            int currentRow = i;
            bool dir = true; //true if going in upward direction
		
	    //loop till stringLength-1
            while(currentRow<len)
            {
                str.append(s,currentRow,1);
		
		//checking for first and last row
                 if (i == 0 || i == numRows - 1) 
                {
                    currentRow += (2 * numRows - 2);
                }
                else
                {
			//if going in upward direction
                    if (dir) 
                    {
                        currentRow += (2 * (numRows - i) - 2);
                    }
			//else for downward direction
                    else
                    {
                        currentRow += i * 2;
                    }
                    dir ^= true;
                }
            }
        }
        return str;
    }
};
