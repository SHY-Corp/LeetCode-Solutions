/*
735. Asteroid Collision
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode.
Two asteroids moving in the same direction will never meet.

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [-2,-1,1,2]
Output: [-2,-1,1,2]
Explanation: The -2 and -1 are moving left, while the 1 and 2 are moving right. Asteroids moving the same direction never meet, so no asteroids will meet each other.
 
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        for(auto i:asteroids)
        {
            if(i<0)
            {
                int n = v.size();
                if(n==0)
                {
                  v.push_back(i);
                }
                else
                {
                    if(v.back()<0)
                        v.push_back(i);
                    else
                    {
                        int d=abs(i);
                        if(v.back()<=d)
                        {
                            int f=0;
                            while(v.back()>0 && v.back()<=d)
                            {  
                                if(v.back()==d)
                                {
                                    v.pop_back();
                                    f=1;
                                    break;
                                }
                                v.pop_back();
                                if(v.size()==0)
                                    break;
                            }
                            if(v.size()==0 && f==0)
                                v.push_back(i);
                            else if(v.size()!=0 && f==0 )
                            {
                                if(v.back()<0)
                                   v.push_back(i);
                            }
                        } 
                            
                    }
                }
            }
            else
                v.push_back(i);
            
        }
        return v;
    }
};
