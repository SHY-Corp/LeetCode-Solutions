/*

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.

*/
//Priority Queue Approach

class Solution {
public:
    struct mycmp
    {
        bool operator()(pair<int,string> a, pair<int,string> b)
        {
            if(a.first!=b.first)
            {
                return a.first>b.first;
            }
            else
            {
                return a.second<b.second;
            }
        }
    };


    vector<string> topKFrequent(vector<string>& words, int k)
    {
        unordered_map<string,int> m;
        vector<string> v;

        for(string i:words)
        {
            m[i]++;
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, mycmp> pq;
        for(auto it:m)
        {
            pq.push(make_pair(it.second,it.first));
            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        while(k--)
        {
            v.insert(v.begin(),pq.top().second);
            pq.pop();
        }

        return v;
    }
};
