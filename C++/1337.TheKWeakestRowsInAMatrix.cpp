class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int soldiers=0;
        vector<int> index;
        set<pair<int,int>> m;  //changed to set from unordered_map and map as they doesn't store repeated values

        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[i].size(); j++)
            {
                //if we encounter a '1' while traversing, increment the soldier variable
                if(mat[i][j]==1)
                    soldiers++;
            }
            //insert the no. of soldiers and the current row they are present in, in a set
            m.insert({soldiers, i});

            //resetting the count of no. of soldiers to 0 after iterating each row
            soldiers=0;
        }

        for(auto itr: m)
        {
            if(k==0)
                break;
            //pushing the k weakest rows in the index vector
            index.push_back(itr.second);
            k--;
        }
        return index;
    }
};

/*
   TC:- O(nlogn), where n=no. of rows
   SC:- O(n), n=no. of rows(pair in a set)
*/
