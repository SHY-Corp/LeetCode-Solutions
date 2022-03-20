class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        //int n = tops.size();
        vector<int> freqA(7,0);
        vector<int> freqB(7,0);

        //storing occurrence of same numbers both in tops and bottoms AT THE SAME INDEX!
        vector<int> same(7,0);

        for(int i=0; i<tops.size(); i++)
        {
            freqA[tops[i]]++;
            freqB[bottoms[i]]++;

            //increment the count if both are same
            if(tops[i]==bottoms[i])
                same[tops[i]]++;
        }

        for(int i=0; i<7; i++)
        {
            //while iterating, we are counting same[i] too, due to which the element may repeat, therefore
            //subtracting it to remove any additional value
            //also,if the occurrence of any element in tops and bottoms = n then this element will fill
            //tops or bottoms.
            if(freqA[i] + freqB[i] - same[i] == tops.size())
                return tops.size() - max(freqA[i], freqB[i]);
        }
        return -1;
    }
};
