class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits)
    {
        map<int, vector<int> > ma;
        string ans = "";
        int sum = 0;
        map<int, int> frq;

	// Storing numbers using their mod value with 3, along with their frequency

        for(int i = 0; i < digits.size(); i++)
        {
            sum += digits[i];
            frq[digits[i]]++;
            if(digits[i]%3 == 0)ma[0].push_back(digits[i]);
            else if(digits[i]%3 == 1)ma[1].push_back(digits[i]);
            else ma[2].push_back(digits[i]);
        }
        bool possible = true;
	
	// sorting number in decreasing order to remove the smallest number lying at rightmost index
        
	for(int i = 0; i < 3; i++)sort(ma[i].rbegin(), ma[i].rend());
        if(sum %3 == 1) 
        {
            if(ma[1].size())
            {
                frq[ma[1].back()]--;
                ma[1].pop_back();
            }
            else if(ma[2].size() > 1) {
                frq[ma[2].back()]--; ma[2].pop_back();
                frq[ma[2].back()]--; ma[2].pop_back();
            } 
            else possible = false;
        } 
        else if(sum%3 == 2)
        {
            if(ma[2].size())
            {
                frq[ma[2].back()]--;
                ma[2].pop_back();
            }
            else if(ma[1].size() > 1) 
            {
                frq[ma[1].back()]--; ma[1].pop_back();
                frq[ma[1].back()]--; ma[1].pop_back();
            } 
            else possible = false;
        }
        if(not possible) return ans;
        for(auto i = frq.begin(); i != frq.end(); i++) 
        {
            int times = i->second;
            int key = i->first;
            string tmp(times, '0'+key);
            ans += tmp;
        }
        reverse(ans.begin(), ans.end());
	
	// handling the special case
	
        if(ans[0] == '0')return "0";
        return ans;
    }
};
