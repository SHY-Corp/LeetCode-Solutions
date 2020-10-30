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
        if(int(keysPressed[i])>int(keysPressed[i-1]))
        {
            maxpos = i;
        }
        else
        {
            maxpos = i-1;
        }
    }
  }
  return char(keysPressed[maxpos]);
  }
};
