//The logic used here is to sort all the strings using comparator function func to ensure the final concatenation leads to the Largest Number

class Solution {
public:
    static bool func(int x,int y)//This func is used to check among the two strings which is to be front and which has to be at the backend
    {
        string s1=to_string(x);
        string s2=to_string(y);
         return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),func);
        string s="";
        for(int i=0;i<nums.size();i++)
              s+=to_string(nums[i]);//Added all strings after getting sorted
        for(int i=0;i<s.length()-1;)
        {
            if(s[0]=='0')
            {
                s.erase(s.begin());//Removing the trailing zeroes 
            }
            else
            {
                break;
            }
        }
        return s;
    }
};
