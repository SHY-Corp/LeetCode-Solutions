/*
Problem-
  You are given a string keysPressed of length n, where keysPressed[i] was the ith key pressed in the testing sequence, and a sorted list releaseTimes, where 
  releaseTimes[i] was the time the ith key was released. Both arrays are 0-indexed. The 0th key was pressed at the time 0, and every subsequent key was 
  pressed at the exact time the previous key was released.
  The tester wants to know the key of the keypress that had the longest duration. The ith keypress had a duration of releaseTimes[i] - releaseTimes[i - 1], 
  and the 0th keypress had a duration of releaseTimes[0].
  
Approach-
   1] First, we got an vector as releaseTimes and string of names of key pressed as keysPressed having same length and arranged accordingly.
   2] Here we are checking the duration by subtracting the key release time with the release time recorded by last key in the given vector.
    NOTE: 
     a] Duration for first element is the value of release time given in the vector itself.
     b] For other elements duration is the subtraction of a release time of that element with release time of previous element in the vector.
     c] maxpos is position of element with maximum duration i.e. the position of key name with max duration
     d] If there are multiple such keypresses with same duration, return the lexicographically largest key of the keypresses.
   3] Using for loop, we are calculating time we are storing maximum duration in max and position of release time with max duration in maxpos.
   4] After checking whole vector for the maximum duration we returned single character of the string (keysPressed) with position as maxpos.
*/

class Solution {
public:
  char slowestKey(vector<int>& releaseTimes, string keysPressed)                          
{
  int max=releaseTimes[0], maxpos=0;
  for(int i=1;i<releaseTimes.size();i++)
  {
    if(max < (releaseTimes[i]-releaseTimes[i-1]))
    {
      max = (releaseTimes[i]-releaseTimes[i-1]);
      maxpos = i;
    }
    else if(max == (releaseTimes[i]-releaseTimes[i-1]))
    {
        if(int(keysPressed[i])>int(keysPressed[i-1])) // comparing lexicographically largest key using ASCII(ASCII value of Character=int(Character))
        {
            maxpos = i;
        }
        else
        {
            maxpos = i-1;
        }
    }
  }
  return char(keysPressed[maxpos]);       // returning key name with maximum duration
  }
};
