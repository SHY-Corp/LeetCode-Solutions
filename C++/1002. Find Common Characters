class Solution {
public:
	vector<string> commonChars(vector<string>& arr) {
	   vector<int> hash1(26, 0);
		vector<int> hash2(26, 0);

		for(auto ch : arr[0])
		{
			hash1[ch - 'a']++;
		}

		for(int i = 1; i < arr.size() ; i++)
		{
			for(auto ch : arr[i])
			{
				hash2[ch-'a']++;
			}

			for(int i = 0 ; i < 26 ; i++)
			{
				hash1[i] = min(hash1[i], hash2[i]);
				hash2[i] = 0;
			}

		}




		vector<string> ans;
		for(int i = 0 ; i < 26 ; i++)

			if(hash1[i] > 0)
			{
				int count = hash1[i];
				while(count--)
				{
					char x = i+ 'a';
					string s ;
					s = x;
					ans.push_back(s);

				}
			}

		return ans;
	}
};
