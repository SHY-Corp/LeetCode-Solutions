class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        //arranging the people in increasing order of their weights; the idea is to pair a light weighted person
        //with a heavy person
        sort(begin(people), end(people));

        //count for number of boats
        int count = 0;

        //for keeping a track of people from the heavier end
        int index = people.size()-1;

        for(int i=0; i<=index; )
        {
            //people[i]<=limit, so if a (light + heavy)pair <= limit, increment i
            if(people[i] + people[index]<=limit)
                i++;
            //index will be decremented either way because the weight of 1 person is not going beyond limit so
            //1 person per boat is a possibility and we increase the count
            index--;

            count++;
        }
        return count;
    }
};

/*
    TC = O(NLogN)
    SC = O(1)
*/
